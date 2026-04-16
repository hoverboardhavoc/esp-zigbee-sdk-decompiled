/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_leave_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_zdo_leave_cb(uint8_t status,void *user_ctx)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined3 in_register_00002029;
  int iVar4;
  char *pcVar5;
  touchlink_event_rejoin_network_t *extraout_a1;
  undefined2 auStack_12 [3];
  
  iVar4 = CONCAT31(in_register_00002029,status);
  if (user_ctx == (void *)0x0) {
    iVar4 = __assert_func(0,0,0);
    user_ctx = extraout_a1;
  }
  if (iVar4 == 0) {
    pcVar5 = (char *)touchlink_commissioning_get();
    cVar1 = *pcVar5;
    if (cVar1 == '\x05') {
      if ((touchlink_event_rejoin_network_t *)user_ctx != (touchlink_event_rejoin_network_t *)0x0)
      goto _L18;
      do {
        user_ctx = (void *)__assert_func(0,0,0,0);
_L18:
        nwk_set_extended_panid(&((touchlink_event_rejoin_network_t *)user_ctx)->ext_panid);
        nwk_set_pan_channel((uint)(0x20 << (((touchlink_event_rejoin_network_t *)user_ctx)->channel
                                           & 0x1f)) >> 5);
        nwk_set_panid(((touchlink_event_rejoin_network_t *)user_ctx)->pan_id);
        nwk_set_short_address(((touchlink_event_rejoin_network_t *)user_ctx)->nwk_addr);
        uVar2 = nwk_get_extended_address();
        uVar3 = touchlink_short_address();
        iVar4 = nwk_address_update(uVar2,uVar3,auStack_12);
      } while (iVar4 != 0);
      nwk_address_lock_ref(auStack_12[0]);
      iVar4 = core_globals_get();
      *(byte *)(iVar4 + 0xb18) = *(byte *)(iVar4 + 0xb18) | 1;
      nwk_secur_set_key(((touchlink_event_rejoin_network_t *)user_ctx)->nwk_key,0);
      nwk_secur_switch_key(0);
      zdo_initiate_commissioning(0x80);
      return;
    }
    if (cVar1 == '\x06') {
      if ((touchlink_event_rejoin_network_t *)user_ctx != (touchlink_event_rejoin_network_t *)0x0) {
        touchlink_commissioning_set_logic_channel
                  (((touchlink_event_rejoin_network_t *)user_ctx)->channel);
        touchlink_zdo_set_rejoin_network_info((touchlink_event_rejoin_network_t *)user_ctx);
      }
      zdo_initiate_rejoin();
      return;
    }
    if (cVar1 == '\x04') {
      if ((touchlink_event_rejoin_network_t *)user_ctx == (touchlink_event_rejoin_network_t *)0x0) {
        user_ctx = (void *)__assert_func(0,0,0);
      }
      nwk_set_extended_panid(&((touchlink_event_rejoin_network_t *)user_ctx)->ext_panid);
      ezb_set_channel_mask(1 << (((touchlink_event_rejoin_network_t *)user_ctx)->channel & 0x1f));
      nwk_set_pan_channel(1 << (((touchlink_event_rejoin_network_t *)user_ctx)->channel & 0x1f) &
                          0x7ffffff);
      nwk_set_panid(((touchlink_event_rejoin_network_t *)user_ctx)->pan_id);
      nwk_set_short_address(((touchlink_event_rejoin_network_t *)user_ctx)->nwk_addr);
      aps_secur_set_distributed(1);
      zdo_initiate_commissioning(2);
      return;
    }
  }
  return;
}

