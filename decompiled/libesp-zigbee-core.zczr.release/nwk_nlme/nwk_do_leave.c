/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_do_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_do_leave(uint8_t reason,_Bool rejoin,_Bool remove_children)

{
  uint uVar1;
  uint uVar2;
  zmsg_t *msg;
  undefined3 in_register_00002029;
  int iVar3;
  undefined3 in_register_0000202d;
  int iVar4;
  undefined2 uStack_32;
  nwk_leave_cnf_t nStack_30;
  
  uVar1 = CONCAT31(in_register_0000202d,rejoin);
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0xac0) != '\0') {
    __assert_func(0,0,0,0);
  }
  iVar3 = nwk_is_joined();
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar4 = nwk_is_authed();
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xac0) = 4;
  iVar3 = core_globals_get();
  *(uint8_t *)(iVar3 + 0xac8) = reason;
  iVar3 = nwk_is_device_zczr();
  if (iVar3 == 0) {
    iVar3 = nwk_is_device_zed();
    if (iVar3 != 0) {
      nwk_ed_stop_keepalive();
      nwk_pim_stop_poll();
      if (CONCAT31(in_register_00002029,reason) == 1) goto _L0;
    }
  }
  else {
    nwk_link_mngr_set_enabled(0);
    nwk_concentrator_stop();
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) & 0xfd;
  }
  if (iVar4 != 0) {
    msg = (zmsg_t *)zmsg_alloc(0x2f);
    if (msg == (zmsg_t *)0x0) {
      remove_children = false;
      msg = (zmsg_t *)__assert_func(0,0);
    }
    nwk_build_leave(msg,0xfffd,rejoin,remove_children);
    nwk_fwd_send_msg(msg);
    return;
  }
_L0:
  uVar2 = 0x1000;
  iVar3 = core_globals_get();
  if ((*(byte *)(iVar3 + 0xb18) & 1) != 0) goto _L0;
_L0:
  do {
    __assert_func(0,0,0,0);
_L0:
    mac_purge_tx_queue();
    nwk_fwd_purge(0xffff);
    if (uVar1 == 0) {
      nwk_get_extended_address();
      iVar3 = nwk_address_ref_by_extended(&uStack_32);
      if (iVar3 != 0) goto _L0;
      nwk_address_unlock_ref(uStack_32);
      nwk_neighbor_table_clear();
      nwk_route_disc_table_clear();
      nwk_route_table_clear();
      iVar3 = core_globals_get();
      *(undefined2 *)(iVar3 + uVar2 + -0x624) = 0xffff;
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + uVar2 + -0x621) = 0;
      nwk_set_short_address(0xffff);
      nStack_30._0_4_ = 0;
      nStack_30.field_1._2_4_ = 0;
      nwk_set_extended_panid(&nStack_30);
      nwk_route_record_table_clear();
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + uVar2 + -0x609) = 0;
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + uVar2 + -0x607) = 0;
      nwk_secur_ctx_clear();
      nwk_address_clear();
      nwk_set_panid(0xffff);
      iVar3 = core_globals_get();
      *(undefined2 *)(iVar3 + uVar2 + -0x5da) = 0;
      iVar3 = nwk_is_device_zed();
      if (iVar3 != 0) {
        iVar3 = core_globals_get();
        *(undefined1 *)(iVar3 + uVar2 + -0x5d8) = 0;
      }
    }
    else {
      uStack_32 = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x53,&uStack_32);
      nStack_30._0_2_ = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x50,&nStack_30);
      iVar3 = core_globals_get();
      if (*(int *)(iVar3 + uVar2 + -0x53c) != 0) {
        iVar3 = core_globals_get();
        nwk_neighbor_table_delete(*(undefined4 *)(iVar3 + uVar2 + -0x53c));
        iVar3 = core_globals_get();
        *(undefined4 *)(iVar3 + uVar2 + -0x53c) = 0;
      }
    }
    ds_delete_common_data();
    iVar3 = core_globals_get();
    uVar1 = uVar1 & 1;
    *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) & 0xfe;
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xac0) = 0;
    iVar3 = core_globals_get();
    uVar2 = remove_children & 1;
    if (*(char *)(iVar3 + 0xac8) == '\0') {
      memset(&nStack_30.field_0x1,0,0xd);
      nStack_30.field_1._10_1_ = (byte)uVar1 | (byte)(uVar2 << 1);
      nStack_30._0_4_ = nStack_30._0_4_ & 0xffffff00;
      nwk_leave_confirm(&nStack_30);
      return;
    }
    if ((byte)(*(char *)(iVar3 + 0xac8) - 1U) < 2) {
      nStack_30._0_4_ = 0;
      nStack_30.field_1._2_4_ = 0;
      nStack_30.field_1._6_4_ = (uint)(byte)((byte)uVar1 | (byte)(uVar2 << 1)) << 0x10;
      nwk_leave_indication((nwk_leave_ind_t *)&nStack_30);
      return;
    }
  } while( true );
}

