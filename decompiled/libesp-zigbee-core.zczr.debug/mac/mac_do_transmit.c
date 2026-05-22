/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_do_transmit(mac_device *dev)

{
  byte bVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  ezb_radio_frame_t *tx_frame;
  ezb_err_t eVar3;
  int iVar4;
  int iVar5;
  mac_device *dev_00;
  
  _Var2 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    return;
  }
  tx_frame = (ezb_radio_frame_t *)mac_pal_get_tx_frame();
  tx_frame->channel = (dev->ctx).phy_channel;
  (tx_frame->info).tx.max_frame_retries = (dev->pib).max_frame_retries;
  (tx_frame->info).tx.max_csma_backoffs = (dev->pib).max_csma_backoffs;
  (tx_frame->info).tx.max_csma_be = (dev->pib).max_be;
  (tx_frame->info).tx.min_csma_be = (dev->pib).min_be;
  bVar1 = (dev->ctx).cur_op;
  if (bVar1 == 5) {
    mac_pal_set_rx_when_idle(1);
    iVar4 = prepare_data_request(dev,tx_frame);
joined_r0x0001216c:
    if (iVar4 != 0) goto _L0;
  }
  else if (bVar1 < 6) {
    if (bVar1 == 3) {
      iVar4 = prepare_association_request(dev,tx_frame);
      goto joined_r0x0001216c;
    }
    if (bVar1 == 4) {
      eVar3 = prepare_direct_data_frame(dev,tx_frame);
      if (eVar3 != 0) goto _L0;
      (dev->pib).dsn = (dev->pib).dsn + '\x01';
      mac_frame_set_seq_num(tx_frame);
      iVar4 = 0;
    }
    else {
      if (bVar1 != 1) goto _L0;
      eVar3 = prepare_beacon_request(dev,tx_frame);
      if (eVar3 != 0) goto _L0;
      mac_pal_set_panid(0xffff);
      mac_pal_set_rx_when_idle(1);
      tx_frame->channel = (dev->ctx).scan_channel;
      iVar4 = 0;
    }
  }
  else {
    if (bVar1 == 7) {
      iVar4 = prepare_beacon(dev,tx_frame);
      goto joined_r0x0001216c;
    }
    if (bVar1 != 8) {
_L0:
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x253,"mac_do_transmit",
                    &_LC7);
      goto _L0;
    }
    eVar3 = prepare_indirect_frame(dev,tx_frame);
    if (eVar3 != 0) goto _L0;
    (dev->pib).dsn = (dev->pib).dsn + '\x01';
    mac_frame_set_seq_num(tx_frame);
    iVar4 = 0;
  }
  iVar5 = mac_pal_transmit();
  if (iVar5 != 0) {
_L0:
    dev_00 = (mac_device *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x259,
                           "mac_do_transmit","(mac_pal_transmit()) == 0");
    eVar3 = mac_update_scan_channel(dev_00);
    if (eVar3 == 0) {
      mac_do_transmit(dev_00);
    }
    else {
      mac_pal_set_panid((dev_00->pib).panid);
      mac_pal_set_rx_when_idle(*(uint *)&(dev_00->pib).transaction_persistence_time >> 0x11 & 1);
      mac_set_state(dev_00,MAC_STATE_NORMAL);
      mac_finish_op(dev_00);
      mac_report_active_scan_result(dev_00,(mac_frame_t *)0x0);
      mac_perform_next_op(dev_00);
    }
    return;
  }
  if (iVar4 == 0) {
    return;
  }
_L0:
  tx_frame->length = '\0';
  mac_handle_transmit_done(dev,tx_frame,(ezb_radio_frame_t *)0x0,8);
  return;
}

