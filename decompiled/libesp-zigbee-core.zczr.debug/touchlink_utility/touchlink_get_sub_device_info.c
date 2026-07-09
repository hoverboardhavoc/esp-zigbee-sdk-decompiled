/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_sub_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_get_sub_device_info(uint param_1,undefined1 *param_2)

{
  undefined3 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  if (param_2 == (undefined1 *)0x0) {
    uVar6 = 2;
  }
  else {
    puVar3 = (undefined1 *)0x0;
    uVar4 = 0;
    while (puVar3 = (undefined1 *)af_get_next_simple_desc(puVar3), puVar3 != (undefined1 *)0x0) {
      if (7 < uVar4) {
        return 5;
      }
      if (uVar4 == param_1) {
        puVar5 = (undefined4 *)nwk_get_extended_address();
        uVar6 = *puVar5;
        uVar1 = *(undefined3 *)(puVar5 + 1);
        uVar2 = puVar5[1];
        *param_2 = (char)*(undefined3 *)puVar5;
        param_2[1] = (char)((uint)uVar6 >> 8);
        param_2[2] = (char)((uint)uVar6 >> 0x10);
        param_2[3] = (char)((uint)uVar6 >> 0x18);
        param_2[4] = (char)uVar1;
        param_2[5] = (char)((uint)uVar2 >> 8);
        param_2[6] = (char)((uint)uVar2 >> 0x10);
        param_2[7] = (char)((uint)uVar2 >> 0x18);
        param_2[8] = *puVar3;
        *(undefined2 *)(param_2 + 10) = *(undefined2 *)(puVar3 + 2);
        *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(puVar3 + 4);
        param_2[0xe] = (byte)*(undefined2 *)(puVar3 + 6) & 0xf;
        param_2[0xf] = 0;
        param_2[0x10] = 0;
        return 0;
      }
      uVar4 = uVar4 + 1 & 0xff;
    }
    uVar6 = 5;
  }
  return uVar6;
}

