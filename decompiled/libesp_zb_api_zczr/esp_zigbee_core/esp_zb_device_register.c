/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_device_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_device_register(void *param_1)

{
  uint *__ptr;
  undefined4 uVar1;
  int iVar2;
  void *__dest;
  int iVar3;
  void *pvVar4;
  size_t __nmemb;
  uint uVar5;
  void *__src;
  
  __nmemb = 0;
  pvVar4 = param_1;
  while (pvVar4 = *(void **)((int)pvVar4 + 0x24), pvVar4 != (void *)0x0) {
    __nmemb = __nmemb + 1 & 0xff;
  }
  __ptr = (uint *)malloc(5);
  if (__ptr == (uint *)0x0) {
_L0:
    uVar1 = 0xffffffff;
  }
  else {
    *(byte *)__ptr = (byte)__nmemb;
    if (__nmemb == 0) {
      *(byte *)((int)__ptr + 1) = 0;
      *(byte *)((int)__ptr + 2) = 0;
      *(byte *)((int)__ptr + 3) = 0;
      *(byte *)(__ptr + 1) = 0;
    }
    else {
      pvVar4 = calloc(__nmemb,4);
      *(byte *)((int)__ptr + 2) = (byte)((uint)pvVar4 >> 8);
      *(byte *)((int)__ptr + 3) = (byte)((uint)pvVar4 >> 0x10);
      *(byte *)((int)__ptr + 1) = (byte)pvVar4;
      *(byte *)(__ptr + 1) = (byte)((uint)pvVar4 >> 0x18);
      if (pvVar4 == (void *)0x0) {
_L0:
        free(__ptr);
        goto _L0;
      }
      uVar5 = 0;
      __src = param_1;
      while (__src = *(void **)((int)__src + 0x24), __src != (void *)0x0) {
        __dest = malloc(0x24);
        *(void **)(uVar5 * 4 + (int)pvVar4) = __dest;
        if (__dest == (void *)0x0) {
          for (iVar2 = 0; pvVar4 = (void *)((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8),
              iVar2 < (int)(uint)(byte)*__ptr; iVar2 = iVar2 + 1) {
            pvVar4 = *(void **)((int)pvVar4 + iVar2 * 4);
            if (pvVar4 != (void *)0x0) {
              free(pvVar4);
            }
          }
          free(pvVar4);
          goto _L0;
        }
        memcpy(__dest,__src,0x24);
        uVar5 = uVar5 + 1 & 0xff;
      }
    }
    esp_zb_internal_zcl_clean_attr_list_from_set();
    esp_zb_internal_zcl_clean_cluster_list_from_set();
    while (param_1 != (void *)0x0) {
      pvVar4 = *(void **)((int)param_1 + 0x24);
      free(param_1);
      param_1 = pvVar4;
    }
    zb_af_register_device_ctx(__ptr);
    iVar2 = zb_zcl_get_ctx();
    *(code **)(iVar2 + 0x9c) = zb_zcl_device_callback;
    iVar2 = zb_zcl_get_ctx();
    *(code **)(iVar2 + 0x94) = zb_zcl_report_attr_callback;
    for (iVar2 = 0; iVar2 < (int)(uint)(byte)*__ptr; iVar2 = iVar2 + 1) {
      if (((byte)(**(char **)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar2 * 4) - 1U) < 0xef
          ) && (iVar3 = zb_af_get_endpoint_desc(), *(int *)(iVar3 + 3) == 0)) {
        iVar3 = zb_af_get_endpoint_desc
                          (**(undefined1 **)
                             (((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar2 * 4));
        *(undefined1 *)(iVar3 + 3) = 0xae;
        *(undefined1 *)(iVar3 + 4) = 10;
        *(undefined1 *)(iVar3 + 5) = 1;
        *(undefined1 *)(iVar3 + 6) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

