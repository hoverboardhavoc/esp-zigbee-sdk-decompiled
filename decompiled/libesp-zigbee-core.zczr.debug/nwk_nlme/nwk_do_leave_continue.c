/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_do_leave_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nwk_do_leave_continue(ezb_err_t error,_Bool rejoin,_Bool remove_children)

{
  int iVar1;
  undefined3 in_register_0000202d;
  int unaff_s3;
  undefined1 auStack_3c [4];
  nwk_addr_ref_t addr_ref;
  undefined4 uStack_34;
  byte bStack_30;
  undefined1 uStack_2f;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = core_globals_get();
  if ((*(byte *)(iVar1 + 0xb18) & 1) == 0) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",0x138,"nwk_do_leave_continue",
                  "(((*core_globals_get()).nwk).ctx).is_joined");
  }
  else {
    mac_purge_tx_queue();
    nwk_fwd_purge(0xffff);
    if (CONCAT31(in_register_0000202d,rejoin) != 0) {
      uStack_2c = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x53,&uStack_2c);
      uStack_2a = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x50,&uStack_2a);
      iVar1 = core_globals_get();
      if (*(int *)(iVar1 + 0xac4) != 0) {
        iVar1 = core_globals_get();
        nwk_neighbor_table_delete(*(undefined4 *)(iVar1 + 0xac4));
        iVar1 = core_globals_get();
        *(undefined4 *)(iVar1 + 0xac4) = 0;
      }
      goto _L0;
    }
  }
  nwk_get_extended_address();
  iVar1 = nwk_address_ref_by_extended(auStack_3c);
  if (iVar1 == 0) {
    nwk_address_unlock_ref((uint)auStack_3c & 0xffff);
    nwk_neighbor_table_clear();
    nwk_route_disc_table_clear();
    nwk_route_table_clear();
    iVar1 = core_globals_get();
    unaff_s3 = 0x1000;
    *(undefined2 *)(iVar1 + 0x9dc) = 0xffff;
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9df) = 0;
    nwk_set_short_address(0xffff);
    uStack_28 = 0;
    uStack_24 = 0;
    nwk_set_extended_panid(&uStack_28);
    nwk_route_record_table_clear();
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9f7) = 0;
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9f9) = 0;
    nwk_secur_ctx_clear();
    nwk_address_clear();
    nwk_set_panid(0xffff);
    iVar1 = core_globals_get();
    *(undefined2 *)(iVar1 + 0xa26) = 0;
    iVar1 = nwk_is_device_zed();
    if (iVar1 == 0) goto _L0;
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",0x149,"nwk_do_leave_continue",
                  "(nwk_address_ref_by_extended(nwk_get_extended_address(), &addr_ref)) == 0");
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + unaff_s3 + -0x5d8) = 0;
_L0:
  ds_delete_common_data();
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb18) = *(byte *)(iVar1 + 0xb18) & 0xfe;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xac0) = 0;
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xac8) == '\0') {
    _addr_ref = 0;
    uStack_34 = 0;
    auStack_3c = (undefined1  [4])(error & 0xff);
    uStack_2f = 0;
    bStack_30 = rejoin | (byte)((remove_children & 1) << 1);
    nwk_leave_confirm((nwk_leave_cnf_t *)auStack_3c);
  }
  else {
    if (1 < (byte)(*(char *)(iVar1 + 0xac8) - 1U)) {
      __assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",0x192,"nwk_do_leave_continue",
                    &_LC18);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    auStack_3c = (undefined1  [4])0x0;
    _addr_ref = 0;
    uStack_34 = (uint)(byte)(rejoin | (byte)((remove_children & 1) << 1)) << 0x10;
    nwk_leave_indication((nwk_leave_ind_t *)auStack_3c);
  }
  return;
}

