/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_ieee_addr_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_ieee_addr_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  void *__dest;
  uint __nmemb;
  code *pcVar5;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  
  pcVar5 = (code *)*param_2;
  if (pcVar5 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar3 = (undefined1 *)param_1[1];
      if (puVar3 == (undefined1 *)0x0) {
        __assert_func(0,0,0,0);
      }
      local_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      puStack_24 = (undefined1 *)0x0;
      memcpy(&local_30,puVar3 + 1,8);
      bVar1 = puVar3[0xc];
      __nmemb = (uint)bVar1;
      uStack_28 = CONCAT22(uStack_28._2_2_,*(undefined2 *)(puVar3 + 10));
      if (__nmemb != 0) {
        puVar4 = (undefined1 *)calloc(1,8);
        puStack_24 = puVar4;
        if (puVar4 != (undefined1 *)0x0) {
          uVar2 = puVar3[0xd];
          puVar4[1] = bVar1;
          *puVar4 = uVar2;
          puVar4[2] = bVar1;
          __dest = calloc(__nmemb,2);
          *(void **)(puVar4 + 4) = __dest;
          if (__dest != (void *)0x0) {
            memcpy(__dest,*(void **)(puVar3 + 0x10),__nmemb << 1);
          }
        }
      }
      (*pcVar5)(*puVar3,&local_30,param_2[1]);
      if (puStack_24 != (undefined1 *)0x0) {
        if (*(void **)(puStack_24 + 4) != (void *)0x0) {
          free(*(void **)(puStack_24 + 4));
        }
        free(puStack_24);
      }
    }
    else if (*param_1 == 7) {
      (*pcVar5)(0x85,0,param_2[1]);
    }
  }
  free(param_2);
  return;
}

