/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_transmit(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = mac_is_enabled();
  if (iVar2 == 0) {
    return;
  }
  iVar2 = mac_pal_get_tx_frame();
  *(undefined1 *)(iVar2 + 5) = *(undefined1 *)(param_1 + 0x41);
  *(undefined1 *)(iVar2 + 0x10) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined1 *)(iVar2 + 0x11) = *(undefined1 *)(param_1 + 0x22);
  *(undefined1 *)(iVar2 + 0x12) = *(undefined1 *)(param_1 + 0x21);
  *(undefined1 *)(iVar2 + 0x13) = *(undefined1 *)(param_1 + 0x20);
  bVar1 = *(byte *)(param_1 + 0x2e);
  if (bVar1 == 5) {
    mac_pal_set_rx_when_idle(1);
    iVar3 = prepare_data_request(param_1,iVar2);
joined_r0x0001216c:
    if (iVar3 != 0) goto _L0;
  }
  else if (bVar1 < 6) {
    if (bVar1 == 3) {
      iVar3 = prepare_association_request(param_1,iVar2);
      goto joined_r0x0001216c;
    }
    if (bVar1 == 4) {
      iVar3 = prepare_direct_data_frame(param_1,iVar2);
      if (iVar3 != 0) goto _L0;
      *(char *)(param_1 + 0xc) = *(char *)(param_1 + 0xc) + '\x01';
      mac_frame_set_seq_num(iVar2);
      iVar3 = 0;
    }
    else {
      if (bVar1 != 1) goto _L0;
      iVar3 = prepare_beacon_request(param_1,iVar2);
      if (iVar3 != 0) goto _L0;
      mac_pal_set_panid(0xffff);
      mac_pal_set_rx_when_idle(1);
      *(undefined1 *)(iVar2 + 5) = *(undefined1 *)(param_1 + 0x32);
      iVar3 = 0;
    }
  }
  else {
    if (bVar1 == 7) {
      iVar3 = prepare_beacon(param_1,iVar2);
      goto joined_r0x0001216c;
    }
    if (bVar1 != 8) {
_L0:
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x253,"mac_do_transmit",
                    &_LC7);
      goto _L0;
    }
    iVar3 = prepare_indirect_frame(param_1,iVar2);
    if (iVar3 != 0) goto _L0;
    *(char *)(param_1 + 0xc) = *(char *)(param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(iVar2);
    iVar3 = 0;
  }
  iVar4 = mac_pal_transmit();
  if (iVar4 != 0) {
_L0:
    iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x259,
                          "mac_do_transmit","(mac_pal_transmit()) == 0");
    iVar3 = mac_update_scan_channel();
    if (iVar3 == 0) {
      mac_do_transmit(iVar2);
    }
    else {
      mac_pal_set_panid(*(undefined2 *)(iVar2 + 10));
      mac_pal_set_rx_when_idle(*(uint *)(iVar2 + 0x28) >> 0x11 & 1);
      mac_set_state(iVar2,0);
      mac_finish_op(iVar2);
      mac_report_active_scan_result(iVar2,0);
      mac_perform_next_op(iVar2);
    }
    return;
  }
  if (iVar3 == 0) {
    return;
  }
_L0:
  *(undefined1 *)(iVar2 + 4) = 0;
  mac_handle_transmit_done(param_1,iVar2,0,8);
  return;
}

