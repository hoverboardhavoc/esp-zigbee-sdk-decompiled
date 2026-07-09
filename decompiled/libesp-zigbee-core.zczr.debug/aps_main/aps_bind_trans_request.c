/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_bind_trans_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_bind_trans_request(int *param_1)

{
  int iVar1;
  int local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 auStack_14 [3];
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x13c,
                  "aps_bind_trans_request","req != ((void *)0) && req->asdu != ((void *)0)");
  }
  else if ((char)param_1[1] == '\0') {
    local_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    auStack_14[0] = 0;
    nwk_get_extended_address();
    local_20 = aps_bind_table_find_src(*(undefined1 *)((int)param_1 + 0xe),(short)param_1[4]);
    if (local_20 == 0) {
      return 0x3a8;
    }
    iVar1 = zmsg_add_footer(*param_1,param_1,0x1c);
    if (iVar1 != 0) {
      return iVar1;
    }
    goto _L0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x13d,
                "aps_bind_trans_request","req->dst_addr.addr_mode == EZB_ADDR_MODE_NONE");
_L0:
  iVar1 = aps_bind_trans_schedule_next_nmsg(local_20,uStack_1c,*param_1,auStack_14);
  if (iVar1 == 0) {
    iVar1 = zmsg_add_footer(*param_1,&local_20,0x10);
  }
  return iVar1;
}

