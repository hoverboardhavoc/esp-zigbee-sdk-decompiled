/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_register_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_mm_register_interface(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar1 = 0;
  do {
    if (uVar1 != 0) {
      puVar7 = (uint *)0x0;
_L0:
      if (puVar7 != (uint *)0x0) {
        *param_2 = (char)uVar1;
        uVar8 = *puVar7;
        *puVar7 = uVar8 & 0xffffffe0 | uVar1;
        *puVar7 = uVar8 & 0xffffff80 | uVar1 | 0x20;
        puVar7[2] = *param_1;
        uVar3 = (param_1[1] & 1) << 7;
        *puVar7 = uVar8 & 0xffffff00 | uVar1 | 0x20 | uVar3;
        uVar4 = (param_1[1] >> 1 & 1) << 8;
        *puVar7 = uVar8 & 0xfffffe00 | uVar1 | 0x20 | uVar3 | uVar4;
        uVar5 = (param_1[1] >> 2 & 1) << 9;
        *puVar7 = uVar8 & 0xfffffc00 | uVar1 | 0x20 | uVar3 | uVar4 | uVar5;
        uVar6 = (param_1[1] >> 3 & 1) << 10;
        *puVar7 = uVar8 & 0xfffff800 | uVar1 | 0x20 | uVar3 | uVar4 | uVar5 | uVar6;
        *puVar7 = uVar8 & 0xfffff000 | uVar1 | 0x20 | uVar3 | uVar4 | uVar5 | uVar6 |
                  (param_1[1] >> 4 & 1) << 0xb;
      }
      return puVar7 == (uint *)0x0;
    }
    iVar2 = core_globals_get();
    if ((*(uint *)(iVar2 + 0xc7c) >> 5 & 3) == 0) {
      iVar2 = core_globals_get();
      puVar7 = (uint *)(iVar2 + 0xc7c);
      goto _L0;
    }
    uVar1 = 1;
  } while( true );
}

