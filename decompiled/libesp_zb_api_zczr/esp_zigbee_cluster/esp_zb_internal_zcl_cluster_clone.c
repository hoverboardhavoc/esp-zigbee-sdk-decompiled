/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_internal_zcl_cluster_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_internal_zcl_cluster_clone(void *param_1,void *param_2)

{
  int iVar1;
  undefined4 auStack_14 [2];
  
  if (param_1 != (void *)0x0) {
    if (param_2 == (void *)0x0) {
      iVar1 = 0x102;
    }
    else {
      memcpy(param_1,param_2,0xf);
      *(undefined1 *)((int)param_1 + 4) = 0;
      *(undefined1 *)((int)param_1 + 5) = 0;
      *(undefined1 *)((int)param_1 + 6) = 0;
      *(undefined1 *)((int)param_1 + 7) = 0;
      if (*(short *)((int)param_2 + 2) != 0) {
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",
                  0xab);
      }
      iVar1 = 0;
      if (*(int *)((int)param_2 + 4) != 0) {
        auStack_14[0] = 0;
        iVar1 = esp_zb_internal_attribute_list_clone(auStack_14);
        if (iVar1 == 0) {
          *(char *)((int)param_1 + 4) = (char)auStack_14[0];
          *(char *)((int)param_1 + 5) = (char)((uint)auStack_14[0] >> 8);
          *(char *)((int)param_1 + 6) = (char)((uint)auStack_14[0] >> 0x10);
          *(char *)((int)param_1 + 7) = (char)((uint)auStack_14[0] >> 0x18);
        }
      }
    }
    return iVar1;
  }
  return 0x102;
}

