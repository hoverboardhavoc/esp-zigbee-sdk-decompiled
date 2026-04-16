/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_device_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010742) */
/* WARNING: Removing unreachable block (ram,0x00010782) */
/* WARNING: Unknown calling convention */

void nwk_handle_device_leave(nwk_leave_ind_t *ind)

{
  uint uVar1;
  zmsg_t *msg;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 remove_children;
  undefined2 uStack_32;
  nwk_leave_cnf_t nStack_30;
  
  iVar2 = nwk_neighbor_table_get_by_extended(&ind->device_address);
  nwk_fwd_purge(ind->short_address);
  iVar3 = nwk_is_device_zed();
  if (iVar3 == 0) {
    nwk_route_table_remove_by_dst(ind->short_address);
    nwk_route_table_remove_by_next_hop(ind->short_address);
    nwk_route_record_table_remove_by_dst(ind->short_address);
    nwk_route_record_table_remove_by_next_hop(ind->short_address);
    if (iVar2 != 0) {
      nwk_neighbor_table_delete(iVar2);
      return;
    }
  }
  else if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0xc) & 0x3c0) == 0)) && ((ind->field_0xa & 2) != 0))
  {
    uVar4 = *(ushort *)&ind->field_0xa >> 1 & 1;
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
    *(undefined1 *)(iVar2 + 0xac8) = 2;
    iVar2 = nwk_is_device_zczr();
    if (iVar2 == 0) {
      iVar2 = nwk_is_device_zed();
      if (iVar2 != 0) {
        nwk_ed_stop_keepalive();
        nwk_pim_stop_poll();
      }
    }
    else {
      nwk_link_mngr_set_enabled(0);
      nwk_concentrator_stop();
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfd;
    }
    if (iVar3 == 0) {
      uVar1 = 0x1000;
      iVar2 = core_globals_get();
      if ((*(byte *)(iVar2 + 0xb18) & 1) != 0) goto _L0;
      while( true ) {
        do {
          __assert_func(0,0,0,0);
_L0:
          mac_purge_tx_queue();
          nwk_fwd_purge(0xffff);
          nwk_get_extended_address();
          iVar2 = nwk_address_ref_by_extended(&uStack_32);
        } while (iVar2 != 0);
        nwk_address_unlock_ref(uStack_32);
        nwk_neighbor_table_clear();
        nwk_route_disc_table_clear();
        nwk_route_table_clear();
        iVar2 = core_globals_get();
        *(undefined2 *)(iVar2 + uVar1 + -0x624) = 0xffff;
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + uVar1 + -0x621) = 0;
        nwk_set_short_address(0xffff);
        nStack_30._0_4_ = 0;
        nStack_30.field_1._2_4_ = 0;
        nwk_set_extended_panid(&nStack_30);
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
        ds_delete_common_data();
        iVar2 = core_globals_get();
        *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfe;
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xac0) = 0;
        iVar2 = core_globals_get();
        if (*(char *)(iVar2 + 0xac8) == '\0') break;
        uVar1 = uVar4;
        if ((byte)(*(char *)(iVar2 + 0xac8) - 1U) < 2) {
          nStack_30._0_4_ = 0;
          nStack_30.field_1._2_4_ = 0;
          nStack_30.field_1._6_4_ = uVar4 << 0x11;
          nwk_leave_indication((nwk_leave_ind_t *)&nStack_30);
          return;
        }
      }
      memset(&nStack_30.field_0x1,0,0xd);
      nStack_30._0_4_ = nStack_30._0_4_ & 0xffffff00;
      nStack_30.field_1._10_1_ = (undefined1)(uVar4 << 1);
      nwk_leave_confirm(&nStack_30);
      return;
    }
    msg = (zmsg_t *)zmsg_alloc(0x2f);
    remove_children = (undefined1)uVar4;
    if (msg == (zmsg_t *)0x0) {
      remove_children = 0;
      msg = (zmsg_t *)__assert_func(0,0);
    }
    nwk_build_leave(msg,0xfffd,false,(_Bool)remove_children);
    nwk_fwd_send_msg(msg);
    return;
  }
  return;
}

