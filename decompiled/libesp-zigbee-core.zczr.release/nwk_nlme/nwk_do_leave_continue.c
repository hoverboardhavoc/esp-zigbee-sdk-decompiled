/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_do_leave_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_do_leave_continue(ezb_err_t error,_Bool rejoin,_Bool remove_children)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  undefined2 uStack_32;
  undefined1 auStack_30 [2];
  nwk_addr_ref_t addr_ref;
  nwk_leave_cnf_t cnf;
  
  uVar1 = CONCAT31(in_register_0000202d,rejoin);
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
      _auStack_30 = 0;
      cnf._0_4_ = 0;
      nwk_set_extended_panid(auStack_30);
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
      auStack_30 = (undefined1  [2])0xffff;
      nwk_mm_set_pib_attr(0xff,0x50,auStack_30);
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
      memset(auStack_30 + 1,0,0xd);
      cnf.field_1._6_1_ = (byte)uVar1 | (byte)(uVar2 << 1);
      auStack_30[0] = (nwk_status_t)error;
      nwk_leave_confirm((nwk_leave_cnf_t *)auStack_30);
      return;
    }
    if ((byte)(*(char *)(iVar3 + 0xac8) - 1U) < 2) {
      _auStack_30 = 0;
      cnf._0_4_ = 0;
      cnf.field_1._2_4_ = (uint)(byte)((byte)uVar1 | (byte)(uVar2 << 1)) << 0x10;
      nwk_leave_indication((nwk_leave_ind_t *)auStack_30);
      return;
    }
  } while( true );
}

