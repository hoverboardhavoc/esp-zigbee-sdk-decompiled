/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_internal_zcl_cluster_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_internal_zcl_cluster_clone(void *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_14 [2];
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Invalid argument in %s\n",uVar2,0x10000,
            "esp_zb_internal_zcl_cluster_clone",0xa5,"esp_zb_internal_zcl_cluster_clone");
    iVar1 = 0x102;
  }
  else {
    memcpy(param_1,param_2,0xf);
    *(undefined1 *)((int)param_1 + 4) = 0;
    *(undefined1 *)((int)param_1 + 5) = 0;
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 7) = 0;
    if (*(short *)((int)param_2 + 2) == 0) {
      if (*(int *)((int)param_2 + 4) != 0) {
        auStack_14[0] = 0;
        iVar1 = esp_zb_internal_attribute_list_clone(auStack_14);
        if (iVar1 != 0) {
          return iVar1;
        }
        *(char *)((int)param_1 + 4) = (char)auStack_14[0];
        *(char *)((int)param_1 + 5) = (char)((uint)auStack_14[0] >> 8);
        *(char *)((int)param_1 + 6) = (char)((uint)auStack_14[0] >> 0x10);
        *(char *)((int)param_1 + 7) = (char)((uint)auStack_14[0] >> 0x18);
        return 0;
      }
    }
    else {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",
                0xab);
    }
    iVar1 = 0;
  }
  return iVar1;
}

