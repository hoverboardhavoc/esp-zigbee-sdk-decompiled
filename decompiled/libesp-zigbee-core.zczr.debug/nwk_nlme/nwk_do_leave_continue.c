/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_do_leave_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void nwk_do_leave_continue(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  int unaff_s3;
  uint unaff_s7;
  uint uStack_48;
  uint uStack_44;
  int iStack_40;
  ushort uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = core_globals_get();
  if ((*(byte *)(iVar1 + 0xb18) & 1) == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x14f,
                  "nwk_do_leave_continue","(((*core_globals_get()).nwk).ctx).is_joined");
  }
  else {
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    nwk_mm_purge_tx_queue(0xff,&uStack_38);
    nwk_fwd_purge_ex(0xffff,0,0);
    if (param_2 != 0) {
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
  iVar1 = nwk_address_ref_by_extended(&uStack_48);
  if (iVar1 == 0) {
    nwk_address_unlock_ref(uStack_48 & 0xffff);
    nwk_neighbor_table_clear();
    nwk_route_disc_table_clear();
    nwk_route_table_clear();
    iVar1 = core_globals_get();
    unaff_s3 = 0x1000;
    *(undefined2 *)(iVar1 + 0x9dc) = 0xffff;
    nwk_set_update_id(0);
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x15f,
                  "nwk_do_leave_continue",
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
    uStack_44 = 0;
    iStack_40 = 0;
    uStack_48 = param_1 & 0xff;
    uStack_3c = (ushort)(byte)((byte)param_2 & 1 | (byte)((param_3 & 1) << 1));
    nwk_leave_confirm(&uStack_48);
  }
  else {
    if (1 < (byte)(*(char *)(iVar1 + 0xac8) - 1U)) {
      pcVar2 = "nwk_do_leave_continue";
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x1a8,&_LC18);
      if (unaff_s7 <= tp) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iVar1 = nwk_validate_leave_request
                        (*(undefined2 *)(param_3 + 6),(int)*(undefined8 *)(pcVar2 + 0x50));
      if (iVar1 != 0) {
        iVar1 = core_globals_get();
        if ((*(char *)(iVar1 + 0xac0) != '\x04') &&
           (iVar1 = core_globals_get(), *(char *)(iVar1 + 0xac0) == '\0')) {
          nwk_do_leave(1,uStack_44 >> 0x10 & 1,uStack_44 >> 0x11 & 1);
        }
      }
      if (param_2 != 0) {
        zmsg_free(param_2);
      }
      return;
    }
    uStack_48 = 0;
    uStack_44 = 0;
    iStack_40 = (param_2 & 1 | (param_3 & 1) << 1) << 0x10;
    nwk_leave_indication(&uStack_48);
  }
  return;
}

