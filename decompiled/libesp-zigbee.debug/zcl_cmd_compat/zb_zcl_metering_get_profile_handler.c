/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_profile_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  void *pvVar2;
  uint __nmemb;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  
  uStack_2c = 0;
  uStack_28 = 0;
  pvStack_24 = (void *)0x0;
  uStack_3c = *param_1;
  uStack_38 = (uint)*(byte *)(param_1 + 3);
  uStack_34 = param_1[4];
  uStack_30 = (uint)*(byte *)(param_1 + 5);
  __ptr = calloc((uint)*(byte *)(param_1 + 5),3);
  if (__ptr == (void *)0x0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
  }
  else {
    pvStack_24 = __ptr;
    if (param_2 != (code *)0x0) {
      (*param_2)(0x43,&uStack_3c);
      uVar1 = esp_err_to_zcl_status();
      *(undefined1 *)(param_1 + 6) = uVar1;
    }
    if (*(char *)(param_1 + 6) == '\0') {
      pvVar2 = calloc(1,0x14);
      param_1[7] = pvVar2;
      if (pvVar2 == (void *)0x0) {
        esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
        return;
      }
      __nmemb = (uint)uStack_28._2_1_;
      *(byte *)((int)pvVar2 + 0xc) = uStack_28._2_1_;
      if (__nmemb != 0) {
        pvVar2 = calloc(__nmemb,4);
        if (pvVar2 == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u24_to_u32(__ptr,__nmemb);
        *(void **)(param_1[7] + 0x10) = pvVar2;
        *(undefined4 *)param_1[7] = uStack_2c;
        *(uint *)(param_1[7] + 4) = uStack_28 & 0xff;
        *(uint *)(param_1[7] + 8) = uStack_28 >> 8 & 0xff;
      }
      param_1[8] = free_memory_for_get_profile;
      param_1[9] = param_1[7];
    }
    free(__ptr);
  }
  return;
}

