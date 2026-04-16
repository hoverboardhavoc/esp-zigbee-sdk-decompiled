/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: addresses */
/* WARNING: Unknown calling convention */

void mac_do_transmit(mac_device *dev)

{
  byte bVar1;
  ushort uVar2;
  ezb_shortaddr_t eVar3;
  char cVar4;
  ezb_radio_frame_t *tx_frame;
  zmsg_queue_t *pzVar5;
  zmsg_t *msg;
  int iVar6;
  uint8_t *__src;
  undefined2 uVar7;
  uint8_t *puVar8;
  uint __n;
  undefined4 uStack_28;
  mac_panids_t panids;
  mac_addresses_t addresses;
  
  tx_frame = (ezb_radio_frame_t *)mac_pal_get_tx_frame();
  tx_frame->channel = (dev->ctx).phy_channel;
  (tx_frame->info).tx.max_frame_retries = (dev->pib).max_frame_retries;
  (tx_frame->info).tx.max_csma_backoffs = (dev->pib).max_csma_backoffs;
  (tx_frame->info).tx.max_csma_be = (dev->pib).max_be;
  (tx_frame->info).tx.min_csma_be = (dev->pib).min_be;
  bVar1 = (dev->ctx).cur_op;
  puVar8 = (uint8_t *)(uint)bVar1;
  if (puVar8 == (uint8_t *)0x5) {
    mac_pal_set_rx_when_idle(1);
    puVar8 = (uint8_t *)0x3;
    panids.source._0_1_ = 3;
    memcpy(&panids.destination,dev,8);
    uStack_28 = CONCAT22((dev->pib).panid,0xffff);
    uVar2 = (dev->pib).short_address;
    if (uVar2 < 0xfffe) {
      panids.source._0_1_ = 2;
      panids.destination = uVar2;
    }
    cVar4 = mac_frame_write_hdr(tx_frame->psdu,&panids,&uStack_28,0,3,4);
    tx_frame->length = cVar4 + '\x02';
    goto _L0;
  }
  if ((uint8_t *)0x5 < puVar8) goto _L0;
  if (puVar8 == (uint8_t *)0x3) {
    panids.source._0_1_ = bVar1;
    memcpy(&panids.destination,dev,8);
    uStack_28 = CONCAT22((dev->pib).panid,0xffff);
    cVar4 = mac_frame_write_hdr(tx_frame->psdu,&panids,&uStack_28,0,3,1);
    tx_frame->length = cVar4 + '\x02';
    (dev->pib).dsn = (dev->pib).dsn + '\x01';
    mac_frame_set_seq_num(tx_frame);
    puVar8 = tx_frame->psdu;
    iVar6 = mac_frame_find_payload_index(tx_frame);
    puVar8 = puVar8 + iVar6;
    puVar8[1] = (dev->ctx).mac_cap_info;
    tx_frame->length = tx_frame->length + '\x01';
    goto _L0;
  }
  if (puVar8 == (uint8_t *)0x4) {
    pzVar5 = &(dev->ctx).tx_q;
    goto _L0;
  }
  if (puVar8 == (uint8_t *)0x1) {
    uStack_28 = 0xffffffff;
    panids.source = 0;
    panids.destination = 0;
    cVar4 = mac_frame_write_hdr(tx_frame->psdu,&panids,&uStack_28,0,7);
    tx_frame->length = cVar4 + '\x02';
    (dev->pib).dsn = (dev->pib).dsn + '\x01';
    mac_frame_set_seq_num(tx_frame);
    mac_pal_set_panid(0xffff);
    mac_pal_set_rx_when_idle(1);
    tx_frame->channel = (dev->ctx).scan_channel;
    goto _L0;
  }
_L0:
  do {
    __assert_func(0,0,0,0);
_L0:
    if (puVar8 == (uint8_t *)0x7) {
      memset((void *)((int)&panids.source + 1),0,0x13);
      panids.source._0_1_ = 2;
      panids.destination = (dev->pib).short_address;
      uStack_28 = CONCAT22(0xffff,(dev->pib).panid);
      cVar4 = mac_frame_write_hdr(tx_frame->psdu,&panids,&uStack_28,0,0,0);
      tx_frame->length = cVar4 + '\x02';
      (dev->pib).bsn = (dev->pib).bsn + '\x01';
      mac_frame_set_seq_num(tx_frame);
      puVar8 = tx_frame->psdu;
      iVar6 = mac_frame_find_payload_index(tx_frame);
      uVar2 = *(ushort *)&(dev->pib).field_0x2a;
      eVar3 = (dev->pib).coord_shortaddr;
      puVar8 = puVar8 + iVar6;
      if ((eVar3 == 0xffff) || (uVar7 = 0x4fff, (dev->pib).short_address != eVar3)) {
        uVar7 = 0xfff;
      }
      *puVar8 = (uint8_t)uVar7;
      puVar8[2] = '\0';
      puVar8[3] = '\0';
      puVar8[1] = (byte)(((uVar2 & 1) << 0xf) >> 8) | (byte)((ushort)uVar7 >> 8);
      __n = 0;
      tx_frame->length = tx_frame->length + '\x04';
      __src = (dev->pib).beacon_payload;
      if ((__src != (uint8_t *)0x0) && (__n = (uint)(dev->pib).beacon_payload_len, __n != 0)) {
        memcpy(puVar8 + 4,__src,__n);
      }
      puVar8 = (uint8_t *)(__n + tx_frame->length);
      tx_frame->length = (uint8_t)puVar8;
    }
    else {
      pzVar5 = &(dev->ctx).itx_q;
      if (puVar8 != (uint8_t *)0x8) goto _L0;
_L0:
      msg = (zmsg_t *)zmsg_queue_get_head(pzVar5);
      if (msg == (zmsg_t *)0x0) goto _L0;
      txframe_from_zmsg(msg,tx_frame);
_L0:
      (dev->pib).dsn = (dev->pib).dsn + '\x01';
      mac_frame_set_seq_num(tx_frame);
    }
_L0:
    iVar6 = mac_pal_transmit();
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}

