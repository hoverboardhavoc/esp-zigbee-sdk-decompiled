/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_leave_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * touchlink_zdo_leave_cb(char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int extraout_a1;
  undefined2 auStack_12 [3];
  
  if (param_2 == 0) {
    param_1 = (char *)__assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  if (param_1 == (char *)0x0) {
    param_1 = (char *)touchlink_commissioning_get();
    cVar1 = *param_1;
    if (cVar1 == '\x05') {
      if (param_2 != 0) goto _L18;
      do {
        param_2 = __assert_func(0,0,0,0);
_L18:
        nwk_set_extended_panid(param_2 + 1);
        nwk_set_pan_channel((uint)(0x20 << (*(byte *)(param_2 + 0xc) & 0x1f)) >> 5);
        nwk_set_panid(*(undefined2 *)(param_2 + 10));
        nwk_set_short_address(*(undefined2 *)(param_2 + 0xe));
        uVar2 = nwk_get_extended_address();
        uVar3 = touchlink_short_address();
        iVar4 = nwk_address_update(uVar2,uVar3,auStack_12);
      } while (iVar4 != 0);
      nwk_address_lock_ref(auStack_12[0]);
      iVar4 = core_globals_get();
      *(byte *)(iVar4 + 0xb18) = *(byte *)(iVar4 + 0xb18) | 1;
      nwk_secur_set_key(param_2 + 0x10,0);
      nwk_secur_switch_key(0);
      zdo_initiate_commissioning(0x80);
      return (char *)0x0;
    }
    if (cVar1 == '\x06') {
      if (param_2 != 0) {
        touchlink_commissioning_set_logic_channel(*(undefined1 *)(param_2 + 0xc));
        touchlink_zdo_set_rejoin_network_info(param_2);
      }
      pcVar5 = (char *)zdo_initiate_rejoin();
      return pcVar5;
    }
    if (cVar1 == '\x04') {
      if (param_2 == 0) {
        param_2 = __assert_func(0,0,0);
      }
      nwk_set_extended_panid(param_2 + 1);
      ezb_set_channel_mask(1 << (*(byte *)(param_2 + 0xc) & 0x1f));
      nwk_set_pan_channel(1 << (*(byte *)(param_2 + 0xc) & 0x1f) & 0x7ffffff);
      nwk_set_panid(*(undefined2 *)(param_2 + 10));
      nwk_set_short_address(*(undefined2 *)(param_2 + 0xe));
      aps_secur_set_distributed(1);
      zdo_initiate_commissioning(2);
      return (char *)0x0;
    }
  }
  return param_1;
}

