/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_do_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_do_leave(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_s3;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xac0) == '\0') {
    unaff_s3 = nwk_is_joined_and_authed();
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac0) = 4;
    iVar1 = core_globals_get();
    *(char *)(iVar1 + 0xac8) = (char)param_1;
    iVar1 = nwk_is_device_zczr();
    if (iVar1 == 0) goto _L0;
    nwk_link_mngr_set_enabled(0);
    nwk_concentrator_stop();
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xb18) = *(byte *)(iVar1 + 0xb18) & 0xfd;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x1af,"nwk_do_leave",
                  0x10c94);
_L0:
    iVar1 = nwk_is_device_zed();
    if (iVar1 != 0) {
      nwk_ed_stop_keepalive();
      nwk_pim_stop_poll();
      if (param_1 == 1) goto _L0;
    }
  }
  if (unaff_s3 != 0) {
    nwk_send_leave(0xfffd,param_2,param_3);
    return;
  }
_L0:
  nwk_do_leave_continue(0,param_2,param_3);
  return;
}

