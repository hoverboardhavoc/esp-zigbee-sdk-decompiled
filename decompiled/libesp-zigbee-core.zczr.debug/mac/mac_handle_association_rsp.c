/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_association_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_association_rsp(int param_1,int param_2)

{
  int extraout_a1;
  char *pcVar1;
  undefined2 uStack_14;
  char cStack_12;
  
  pcVar1 = *(char **)(param_2 + 0x24);
  if (*pcVar1 == '\x02') {
    uStack_14 = *(undefined2 *)(pcVar1 + 1);
    cStack_12 = pcVar1[3];
    if (*(char *)(param_2 + 0xe) != '\x03') goto _L0;
  }
  else {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x3f8,
                            "mac_handle_association_rsp","*cmd_ptr++ == 2U");
    param_2 = extraout_a1;
  }
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
_L0:
  mac_finish_association(&uStack_14);
  return;
}

