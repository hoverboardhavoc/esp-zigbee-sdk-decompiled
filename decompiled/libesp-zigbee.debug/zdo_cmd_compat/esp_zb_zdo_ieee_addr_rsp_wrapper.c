/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_ieee_addr_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_ieee_addr_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  void *pvVar2;
  int iVar3;
  code *pcVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 *puStack_24;
  
  pcVar4 = (code *)*param_2;
  if (pcVar4 == (code *)0x0) goto _L0;
  if (*param_1 != 0) {
    if (*param_1 == 7) {
      (*pcVar4)(0x85,0,param_2[1]);
    }
    goto _L0;
  }
  if (param_1[1] == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                  ,0xc3,"esp_zb_zdo_ieee_addr_rsp_wrapper","result->rsp");
_L0:
    puVar1 = (undefined1 *)calloc(1,8);
    puStack_24 = puVar1;
    if (puVar1 != (undefined1 *)0x0) {
      iVar3 = param_1[1];
      *puVar1 = *(undefined1 *)(iVar3 + 0xd);
      puVar1[1] = *(undefined1 *)(iVar3 + 0xc);
      puVar1[2] = *(undefined1 *)(param_1[1] + 0xc);
      pvVar2 = calloc((uint)*(byte *)(param_1[1] + 0xc),2);
      *(void **)(puVar1 + 4) = pvVar2;
      if (*(void **)(puStack_24 + 4) != (void *)0x0) {
        memcpy(*(void **)(puStack_24 + 4),*(void **)(param_1[1] + 0x10),
               (uint)*(byte *)(param_1[1] + 0xc) << 1);
      }
    }
  }
  else {
    puStack_24 = (undefined1 *)0x0;
    iVar3 = param_1[1];
    local_30 = *(undefined4 *)(iVar3 + 1);
    uStack_2c = *(undefined4 *)(iVar3 + 5);
    uStack_28 = (uint)*(ushort *)(iVar3 + 10);
    if (*(char *)(iVar3 + 0xc) != '\0') goto _L0;
  }
  (*pcVar4)(*(undefined1 *)param_1[1],&local_30,param_2[1]);
  if (puStack_24 != (undefined1 *)0x0) {
    if (*(void **)(puStack_24 + 4) != (void *)0x0) {
      free(*(void **)(puStack_24 + 4));
    }
    free(puStack_24);
  }
_L0:
  free(param_2);
  return;
}

