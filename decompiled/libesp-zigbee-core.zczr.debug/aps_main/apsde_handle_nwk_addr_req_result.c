/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> apsde_handle_nwk_addr_req_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsde_handle_nwk_addr_req_result(int param_1,int param_2,char *param_3)

{
  int iVar1;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x290,
                  "apsde_handle_nwk_addr_req_result",
                  "result != ((void *)0) && user_ctx != ((void *)0)");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x299,
                  "apsde_handle_nwk_addr_req_result","req.dst_addr.addr_mode == EZB_ADDR_MODE_EXT");
  }
  else {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    zmsg_get_footer(param_2,&uStack_2c,0x1c);
    zmsg_remove_footer(param_2,0x1c);
    param_3 = (char *)((uStack_28 & 0xff) - 3);
    if (param_3 != (char *)0x0) goto _L0;
    param_3 = *(char **)(param_1 + 4);
    if (param_3 == (char *)0x0) {
      iVar1 = 0x3a9;
      goto _L0;
    }
    if (*param_3 != '\0') {
      iVar1 = 0x3a9;
      goto _L0;
    }
  }
  iVar1 = apsde_data_request_continue(&uStack_2c,*(undefined2 *)(param_3 + 10));
  if (iVar1 == 0) {
    return;
  }
_L0:
  zmsg_add_footer(param_2,&uStack_2c,0x1c);
  zmsg_set_offset(param_2,0);
  aps_send_data_confirm(param_2,iVar1);
  return;
}

