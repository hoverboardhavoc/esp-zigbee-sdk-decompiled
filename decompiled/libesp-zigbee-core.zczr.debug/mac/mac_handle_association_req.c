/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_association_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_association_req(int param_1,int param_2)

{
  int extraout_a1;
  char *pcVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  char cStack_14;
  
  pcVar1 = *(char **)(param_2 + 0x24);
  if (*pcVar1 == '\x01') {
    if (*(char *)(param_2 + 0xe) != '\x03') {
      return;
    }
  }
  else {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x45f,
                            "mac_handle_association_req","*cmd_ptr++ == 1U");
    param_2 = extraout_a1;
  }
  uStack_1c = *(undefined4 *)(param_2 + 0x10);
  uStack_18 = *(undefined4 *)(param_2 + 0x14);
  cStack_14 = pcVar1[1];
  nwk_mm_asso_indication(*(undefined1 *)(param_1 + 0x2c),&uStack_1c);
  return;
}

