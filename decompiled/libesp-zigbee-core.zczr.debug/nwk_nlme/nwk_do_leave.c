/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_do_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_do_leave(uint8_t reason,_Bool rejoin,_Bool remove_children)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined3 extraout_var;
  int unaff_s3;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xac0) == '\0') {
    _Var1 = nwk_is_joined_and_authed();
    unaff_s3 = CONCAT31(extraout_var,_Var1);
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xac0) = 4;
    iVar2 = core_globals_get();
    *(uint8_t *)(iVar2 + 0xac8) = reason;
    iVar2 = nwk_is_device_zczr();
    if (iVar2 == 0) goto _L0;
    nwk_link_mngr_set_enabled(0);
    nwk_concentrator_stop();
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfd;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x1ab,"nwk_do_leave",
                  0x10c8c);
_L0:
    iVar2 = nwk_is_device_zed();
    if (iVar2 != 0) {
      nwk_ed_stop_keepalive();
      nwk_pim_stop_poll();
      if (CONCAT31(in_register_00002029,reason) == 1) goto _L0;
    }
  }
  if (unaff_s3 != 0) {
    nwk_send_leave(0xfffd,rejoin,remove_children);
    return;
  }
_L0:
  nwk_do_leave_continue(0,rejoin,remove_children);
  return;
}

