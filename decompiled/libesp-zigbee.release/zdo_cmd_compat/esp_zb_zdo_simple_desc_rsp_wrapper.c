/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_simple_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_simple_desc_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  size_t __nmemb;
  code *pcVar2;
  ushort local_30;
  undefined2 uStack_2e;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  
  pcVar2 = (code *)*param_2;
  if (pcVar2 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar1 = (undefined1 *)param_1[1];
      if (puVar1 == (undefined1 *)0x0) {
        __assert_func(0,0,0,0);
      }
      _local_30 = CONCAT22(*(undefined2 *)(puVar1 + 10),(ushort)(byte)puVar1[8]);
      __nmemb = (uint)(byte)puVar1[0xf] + (uint)(byte)puVar1[0x10];
      uStack_2c = *(uint *)(puVar1 + 0xc) & 0xff0fffff;
      uStack_28 = (uint)(byte)puVar1[0x10];
      pvStack_24 = calloc(__nmemb,2);
      if (pvStack_24 != (void *)0x0) {
        memcpy(pvStack_24,*(void **)(puVar1 + 0x14),__nmemb * 2);
      }
      (*pcVar2)(*puVar1,&local_30,param_2[1]);
      if (pvStack_24 != (void *)0x0) {
        free(pvStack_24);
      }
    }
    else {
      (*pcVar2)(0x85,0,param_2[1]);
    }
  }
  free(param_2);
  return;
}

