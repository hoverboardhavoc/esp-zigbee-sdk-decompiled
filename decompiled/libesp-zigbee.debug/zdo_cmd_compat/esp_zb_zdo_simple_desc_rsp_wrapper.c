/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_simple_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_simple_desc_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  size_t __nmemb;
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  ushort local_30;
  undefined2 uStack_2e;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  
  pcVar3 = (code *)*param_2;
  if (pcVar3 != (code *)0x0) {
    puVar1 = param_2;
    if (*param_1 == 0) {
      if (param_1[1] != 0) {
        pvStack_24 = (void *)0x0;
        iVar2 = param_1[1];
        _local_30 = CONCAT22(*(undefined2 *)(iVar2 + 10),(ushort)*(byte *)(iVar2 + 8));
        uStack_2c = *(uint *)(iVar2 + 0xc) & 0xff0fffff;
        uStack_28 = (uint)*(byte *)(iVar2 + 0x10);
        __nmemb = (uint)*(byte *)(iVar2 + 0xf) + (uint)*(byte *)(iVar2 + 0x10);
        pvStack_24 = calloc(__nmemb,2);
        if (pvStack_24 != (void *)0x0) {
          memcpy(pvStack_24,*(void **)(param_1[1] + 0x14),__nmemb * 2);
        }
        (*pcVar3)(*(undefined1 *)param_1[1],&local_30,param_2[1]);
        if (pvStack_24 != (void *)0x0) {
          free(pvStack_24);
        }
        goto _L0;
      }
      puVar1 = (undefined4 *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                             ,0x140,"esp_zb_zdo_simple_desc_rsp_wrapper","result->rsp");
    }
    (*pcVar3)(0x85,0,puVar1[1]);
  }
_L0:
  free(param_2);
  return;
}

