/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_get_sub_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_get_sub_device_info(uint param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  if (param_2 == (undefined1 *)0x0) {
    return 2;
  }
  puVar5 = (undefined1 *)0x0;
  for (uVar7 = 0;
      (puVar5 = (undefined1 *)af_get_next_simple_desc(puVar5), puVar5 != (undefined1 *)0x0 &&
      (uVar7 != 8)); uVar7 = uVar7 + 1 & 0xff) {
    if (uVar7 == param_1) {
      puVar6 = (undefined4 *)nwk_get_extended_address();
      uVar2 = *puVar6;
      uVar3 = *(undefined3 *)(puVar6 + 1);
      uVar4 = puVar6[1];
      *param_2 = (char)*(undefined3 *)puVar6;
      param_2[1] = (char)((uint)uVar2 >> 8);
      param_2[3] = (char)((uint)uVar2 >> 0x18);
      param_2[5] = (char)((uint)uVar4 >> 8);
      param_2[2] = (char)((uint)uVar2 >> 0x10);
      param_2[4] = (char)uVar3;
      param_2[6] = (char)((uint)uVar4 >> 0x10);
      param_2[7] = (char)((uint)uVar4 >> 0x18);
      param_2[8] = *puVar5;
      *(undefined2 *)(param_2 + 10) = *(undefined2 *)(puVar5 + 2);
      *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(puVar5 + 4);
      uVar1 = *(undefined2 *)(puVar5 + 6);
      param_2[0xf] = 0;
      param_2[0x10] = 0;
      param_2[0xe] = (byte)uVar1 & 0xf;
      return 0;
    }
  }
  return 5;
}

