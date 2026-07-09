/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_simple_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_device_simple_desc_init(int param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  
  if (param_1 == 0) {
    uVar2 = 2;
_L0:
    if ((param_1 != 0) && (*(int *)(param_1 + 0x18) != 0)) {
      mm_free();
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  else {
    puVar1 = *(undefined2 **)(param_1 + 4);
    for (puVar7 = puVar1; puVar7 != (undefined2 *)0x0; puVar7 = *(undefined2 **)(puVar7 + 8)) {
      if (*(char *)(puVar7 + 1) == '\x01') {
        *(char *)(param_1 + 0x13) = *(char *)(param_1 + 0x13) + '\x01';
      }
      else {
        if (*(char *)(puVar7 + 1) != '\x02') {
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x2db,
                        "af_device_simple_desc_init",&_LC0);
          break;
        }
        *(char *)(param_1 + 0x14) = *(char *)(param_1 + 0x14) + '\x01';
      }
    }
    uVar4 = (uint)*(byte *)(param_1 + 0x13);
    iVar6 = uVar4 + *(byte *)(param_1 + 0x14);
    if (iVar6 != 0) {
      pvVar3 = calloc(1,iVar6 * 2);
      *(void **)(param_1 + 0x18) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        uVar2 = 1;
        goto _L0;
      }
      uVar5 = 0;
      for (; puVar1 != (undefined2 *)0x0; puVar1 = *(undefined2 **)(puVar1 + 8)) {
        if (*(char *)(puVar1 + 1) == '\x01') {
          *(undefined2 *)(*(int *)(param_1 + 0x18) + uVar5 * 2) = *puVar1;
          uVar5 = uVar5 + 1 & 0xffff;
        }
        else {
          if (*(char *)(puVar1 + 1) != '\x02') {
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x2ea,
                          "af_device_simple_desc_init",&_LC0);
            break;
          }
          *(undefined2 *)(uVar4 * 2 + *(int *)(param_1 + 0x18)) = *puVar1;
          uVar4 = uVar4 + 1 & 0xffff;
        }
      }
    }
    af_add_simple_desc(param_1 + 0xc);
    uVar2 = 0;
  }
  return uVar2;
}

