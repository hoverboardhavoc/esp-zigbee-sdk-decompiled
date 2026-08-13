/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_target_start_network_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_zdo_target_start_network_response(int param_1)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = core_globals_get();
  if (*(int *)(iVar6 + 0xc) == 0 && *(int *)(iVar6 + 0x10) == 0) {
    puVar7 = (undefined4 *)nwk_get_extended_address();
    uVar1 = *puVar7;
    uVar2 = *(undefined3 *)(puVar7 + 1);
    uVar3 = puVar7[1];
    *(char *)(param_1 + 1) = (char)*(undefined3 *)puVar7;
    *(char *)(param_1 + 2) = (char)((uint)uVar1 >> 8);
    *(char *)(param_1 + 3) = (char)((uint)uVar1 >> 0x10);
    *(char *)(param_1 + 4) = (char)((uint)uVar1 >> 0x18);
    *(char *)(param_1 + 5) = (char)uVar2;
    *(char *)(param_1 + 6) = (char)((uint)uVar3 >> 8);
    *(char *)(param_1 + 7) = (char)((uint)uVar3 >> 0x10);
    *(char *)(param_1 + 8) = (char)((uint)uVar3 >> 0x18);
  }
  else {
    iVar6 = core_globals_get();
    uVar1 = *(undefined4 *)(iVar6 + 0xc);
    uVar2 = *(undefined3 *)(iVar6 + 0x10);
    uVar3 = *(undefined4 *)(iVar6 + 0x10);
    *(char *)(param_1 + 1) = (char)*(undefined3 *)(iVar6 + 0xc);
    *(char *)(param_1 + 2) = (char)((uint)uVar1 >> 8);
    *(char *)(param_1 + 3) = (char)((uint)uVar1 >> 0x10);
    *(char *)(param_1 + 4) = (char)((uint)uVar1 >> 0x18);
    *(char *)(param_1 + 5) = (char)uVar2;
    *(char *)(param_1 + 6) = (char)((uint)uVar3 >> 8);
    *(char *)(param_1 + 7) = (char)((uint)uVar3 >> 0x10);
    *(char *)(param_1 + 8) = (char)((uint)uVar3 >> 0x18);
  }
  if (*(char *)(param_1 + 0xc) == '\0') {
    uVar4 = touchlink_assign_random_channel();
    *(undefined1 *)(param_1 + 0xc) = uVar4;
  }
  uVar5 = touchlink_generate_pan_id(*(undefined2 *)(param_1 + 10));
  *(undefined2 *)(param_1 + 10) = uVar5;
  touchlink_send_network_start_rsp(param_1);
  return;
}

