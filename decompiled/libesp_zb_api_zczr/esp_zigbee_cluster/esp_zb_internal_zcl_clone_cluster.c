/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_internal_zcl_clone_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_internal_zcl_clone_cluster(void *param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  uint __nmemb;
  uint uVar4;
  
  if (param_1 == (void *)0x0) {
    return 0x102;
  }
  uVar3 = 0x102;
  if (param_2 != (void *)0x0) {
    memcpy(param_1,param_2,0xf);
    __nmemb = (uint)*(ushort *)((int)param_2 + 2);
    if (__nmemb == 0) {
      *(undefined1 *)((int)param_1 + 4) = 0;
      *(undefined1 *)((int)param_1 + 5) = 0;
      *(undefined1 *)((int)param_1 + 6) = 0;
      *(undefined1 *)((int)param_1 + 7) = 0;
    }
    else {
      pvVar1 = calloc(__nmemb,10);
      *(char *)((int)param_1 + 5) = (char)((uint)pvVar1 >> 8);
      *(char *)((int)param_1 + 6) = (char)((uint)pvVar1 >> 0x10);
      *(char *)((int)param_1 + 4) = (char)pvVar1;
      *(char *)((int)param_1 + 7) = (char)((uint)pvVar1 >> 0x18);
      uVar4 = 0;
      if (pvVar1 == (void *)0x0) {
        return 0x101;
      }
      do {
        iVar2 = esp_zb_internal_zcl_clone_attribute
                          (uVar4 * 10 + *(int *)((int)param_1 + 4),
                           *(int *)((int)param_2 + 4) + uVar4 * 10);
        if (iVar2 != 0) {
          iVar2 = 0;
          if (*(int *)((int)param_1 + 4) == 0) {
            return 0x101;
          }
          for (; iVar2 < (int)(uint)*(ushort *)((int)param_1 + 2); iVar2 = iVar2 + 1) {
            free(*(void **)((int)*(void **)((int)param_1 + 4) + iVar2 * 10 + 6));
          }
          free(*(void **)((int)param_1 + 4));
          *(undefined1 *)((int)param_1 + 4) = 0;
          *(undefined1 *)((int)param_1 + 5) = 0;
          *(undefined1 *)((int)param_1 + 6) = 0;
          *(undefined1 *)((int)param_1 + 7) = 0;
          return 0x101;
        }
        uVar4 = uVar4 + 1;
      } while ((uVar4 & 0xffff) < __nmemb);
    }
    uVar3 = 0;
  }
  return uVar3;
}

