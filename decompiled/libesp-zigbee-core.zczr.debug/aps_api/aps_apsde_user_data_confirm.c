/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> aps_apsde_user_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_apsde_user_data_confirm(undefined4 *param_1)

{
  int unaff_s1;
  int iVar1;
  int unaff_s2;
  int unaff_s3;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_28;
  undefined2 uStack_26;
  int iStack_24;
  
  if (param_1 == (undefined4 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",99,
                  "aps_apsde_user_data_confirm","cnf != ((void *)0)");
_L0:
    if (unaff_s1 == 0) goto _L0;
    log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.confirm");
    unaff_s1 = 0;
  }
  else {
    unaff_s3 = param_1[5];
    if (s_apsde_data_confirm_handler == (code *)0x0) goto _L0;
    unaff_s1 = zmsg_get_length(unaff_s3);
    unaff_s2 = mm_alloc_notrap(1,unaff_s1);
    if (unaff_s2 == 0) goto _L0;
_L0:
    iVar1 = zmsg_read_bytes(unaff_s3,0,unaff_s1,unaff_s2);
    if (iVar1 != unaff_s1) {
      s_apsde_data_ind_handler =
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",0x70,
                         "aps_apsde_user_data_confirm",
                         "asdu_length == zmsg_read_bytes(msg, 0, asdu_length, asdu)");
      return;
    }
  }
  uStack_38 = *param_1;
  uStack_34 = param_1[1];
  uStack_30 = *(undefined2 *)(param_1 + 2);
  uStack_2e = *(undefined1 *)((int)param_1 + 10);
  uStack_2d = *(undefined1 *)((int)param_1 + 0xb);
  uStack_2c = *(undefined2 *)(param_1 + 3);
  uStack_2a = *(undefined2 *)((int)param_1 + 0xe);
  uStack_28 = *(undefined1 *)(param_1 + 4);
  uStack_26 = (undefined2)unaff_s1;
  iStack_24 = unaff_s2;
  (*s_apsde_data_confirm_handler)(&uStack_38,s_apsde_data_confirm_handler);
  if (unaff_s2 != 0) {
    mm_free(unaff_s2);
  }
_L0:
  if (unaff_s3 != 0) {
    zmsg_free(unaff_s3);
  }
  return;
}

