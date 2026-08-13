/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_do_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_do_leave(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  byte bStack_24;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xac0) != '\0') {
    __assert_func(0,0,0,0);
  }
  iVar2 = nwk_is_joined();
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = nwk_is_authed();
  }
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xac0) = 4;
  iVar2 = core_globals_get();
  *(char *)(iVar2 + 0xac8) = (char)param_1;
  iVar2 = nwk_is_device_zczr();
  if (iVar2 == 0) {
    iVar2 = nwk_is_device_zed();
    if (iVar2 != 0) {
      nwk_ed_stop_keepalive();
      nwk_pim_stop_poll();
      if (param_1 == 1) goto _L0;
    }
  }
  else {
    nwk_link_mngr_set_enabled(0);
    nwk_concentrator_stop();
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfd;
  }
  if (iVar3 != 0) {
    iVar2 = zmsg_alloc(0x2f);
    if (iVar2 == 0) {
      iVar2 = __assert_func(0,0,0);
    }
    nwk_build_leave(0xfffd,param_2);
    nwk_fwd_send_msg_delayed(iVar2,0);
    return;
  }
_L0:
  uVar1 = 0x1000;
  iVar2 = core_globals_get();
  if ((*(byte *)(iVar2 + 0xb18) & 1) != 0) goto _L0;
_L0:
  do {
    __assert_func(0,0,0,0);
_L0:
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    nwk_mm_purge_tx_queue(0xff,&uStack_3c);
    nwk_fwd_purge_ex(0xffff,0,0);
    if (param_2 == 0) {
      nwk_get_extended_address();
      iVar2 = nwk_address_ref_by_extended(&uStack_3e);
      if (iVar2 != 0) goto _L0;
      nwk_address_unlock_ref(uStack_3e);
      nwk_neighbor_table_clear();
      nwk_route_disc_table_clear();
      nwk_route_table_clear();
      iVar2 = core_globals_get();
      *(undefined2 *)(iVar2 + uVar1 + -0x624) = 0xffff;
      nwk_set_update_id(0);
      nwk_set_short_address(0xffff);
      uStack_30 = 0;
      uStack_2c = 0;
      nwk_set_extended_panid(&uStack_30);
      nwk_route_record_table_clear();
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + uVar1 + -0x609) = 0;
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + uVar1 + -0x607) = 0;
      nwk_secur_ctx_clear();
      nwk_address_clear();
      nwk_set_panid(0xffff);
      iVar2 = core_globals_get();
      *(undefined2 *)(iVar2 + uVar1 + -0x5da) = 0;
      iVar2 = nwk_is_device_zed();
      if (iVar2 != 0) {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + uVar1 + -0x5d8) = 0;
      }
    }
    else {
      uStack_30 = CONCAT22(uStack_30._2_2_,0xffff);
      nwk_mm_set_pib_attr(0xff,0x53,&uStack_30);
      uStack_3e = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x50,&uStack_3e);
      iVar2 = core_globals_get();
      if (*(int *)(iVar2 + uVar1 + -0x53c) != 0) {
        iVar2 = core_globals_get();
        nwk_neighbor_table_delete(*(undefined4 *)(iVar2 + uVar1 + -0x53c));
        iVar2 = core_globals_get();
        *(undefined4 *)(iVar2 + uVar1 + -0x53c) = 0;
      }
    }
    ds_delete_common_data();
    iVar2 = core_globals_get();
    param_2 = param_2 & 1;
    *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfe;
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xac0) = 0;
    iVar2 = core_globals_get();
    uVar1 = param_3 & 1;
    if (*(char *)(iVar2 + 0xac8) == '\0') {
      memset((void *)((int)&uStack_30 + 1),0,0xd);
      bStack_24 = (byte)param_2 | (byte)(uVar1 << 1);
      uStack_30 = uStack_30 & 0xffffff00;
      nwk_leave_confirm(&uStack_30);
      return;
    }
    if ((byte)(*(char *)(iVar2 + 0xac8) - 1U) < 2) {
      uStack_30 = 0;
      uStack_2c = 0;
      iStack_28 = (uint)(byte)((byte)param_2 | (byte)(uVar1 << 1)) << 0x10;
      nwk_leave_indication(&uStack_30);
      return;
    }
  } while( true );
}

