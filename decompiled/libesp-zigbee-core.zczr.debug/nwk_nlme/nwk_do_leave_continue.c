/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  ezb_shortaddr_t dst_addr;
  undefined3 in_register_0000202d;
  int iVar3;
  undefined1 rejoin_00;
  undefined3 in_register_00002031;
  int unaff_s3;
  uint unaff_s7;
  undefined1 auStack_48 [4];
  nwk_addr_ref_t addr_ref;
  undefined4 uStack_40;
  byte bStack_3c;
  undefined1 uStack_3b;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = CONCAT31(in_register_0000202d,rejoin);
  iVar2 = core_globals_get();
  if ((*(byte *)(iVar2 + 0xb18) & 1) == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x14b,
                  "nwk_do_leave_continue","(((*core_globals_get()).nwk).ctx).is_joined");
  }
  else {
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    nwk_mm_purge_tx_queue(0xff,&uStack_38);
    nwk_fwd_purge_ex(0xffff,0,0);
    if (iVar3 != 0) {
      uStack_2c = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x53,&uStack_2c);
      uStack_2a = 0xffff;
      nwk_mm_set_pib_attr(0xff,0x50,&uStack_2a);
      iVar2 = core_globals_get();
      if (*(int *)(iVar2 + 0xac4) != 0) {
        iVar2 = core_globals_get();
        nwk_neighbor_table_delete(*(undefined4 *)(iVar2 + 0xac4));
        iVar2 = core_globals_get();
        *(undefined4 *)(iVar2 + 0xac4) = 0;
      }
      goto _L0;
    }
  }
  nwk_get_extended_address();
  iVar2 = nwk_address_ref_by_extended(auStack_48);
  if (iVar2 == 0) {
    nwk_address_unlock_ref((uint)auStack_48 & 0xffff);
    nwk_neighbor_table_clear();
    nwk_route_disc_table_clear();
    nwk_route_table_clear();
    iVar2 = core_globals_get();
    unaff_s3 = 0x1000;
    *(undefined2 *)(iVar2 + 0x9dc) = 0xffff;
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x9df) = 0;
    nwk_set_short_address(0xffff);
    uStack_28 = 0;
    uStack_24 = 0;
    nwk_set_extended_panid(&uStack_28);
    nwk_route_record_table_clear();
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x9f7) = 0;
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x9f9) = 0;
    nwk_secur_ctx_clear();
    nwk_address_clear();
    nwk_set_panid(0xffff);
    iVar2 = core_globals_get();
    *(undefined2 *)(iVar2 + 0xa26) = 0;
    iVar2 = nwk_is_device_zed();
    if (iVar2 == 0) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x15b,
                  "nwk_do_leave_continue",
                  "(nwk_address_ref_by_extended(nwk_get_extended_address(), &addr_ref)) == 0");
  }
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + unaff_s3 + -0x5d8) = 0;
_L0:
  ds_delete_common_data();
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfe;
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xac0) = 0;
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xac8) == '\0') {
    _addr_ref = 0;
    uStack_40 = 0;
    auStack_48 = (undefined1  [4])(error & 0xff);
    uStack_3b = 0;
    bStack_3c = rejoin | (byte)((remove_children & 1) << 1);
    nwk_leave_confirm((nwk_leave_cnf_t *)auStack_48);
  }
  else {
    if (1 < (byte)(*(char *)(iVar2 + 0xac8) - 1U)) {
      rejoin_00 = 0xdc;
      dst_addr = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x1a4,
                               &_LC18);
      if (unaff_s7 <= tp) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      _Var1 = nwk_validate_leave_request
                        (*(ezb_shortaddr_t *)(CONCAT31(in_register_00002031,remove_children) + 6),
                         dst_addr,(_Bool)rejoin_00);
      if (CONCAT31(extraout_var,_Var1) != 0) {
        iVar2 = core_globals_get();
        if ((*(char *)(iVar2 + 0xac0) != '\x04') &&
           (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xac0) == '\0')) {
          nwk_do_leave('\x01',(_Bool)((byte)((uint)_addr_ref >> 0x10) & 1),
                       (_Bool)((byte)((uint)_addr_ref >> 0x11) & 1));
        }
      }
      if (iVar3 != 0) {
        zmsg_free(iVar3);
      }
      return;
    }
    auStack_48 = (undefined1  [4])0x0;
    _addr_ref = 0;
    uStack_40 = (uint)(byte)(rejoin | (byte)((remove_children & 1) << 1)) << 0x10;
    nwk_leave_indication((nwk_leave_ind_t *)auStack_48);
  }
  return;
}

