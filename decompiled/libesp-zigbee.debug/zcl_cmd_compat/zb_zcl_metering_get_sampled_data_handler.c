/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_sampled_data_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_sampled_data_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  void *pvVar2;
  uint __nmemb;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  ushort uStack_38;
  ushort uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  pvStack_24 = (void *)0x0;
  uStack_44 = *param_1;
  uStack_40 = (uint)*(ushort *)(param_1 + 3);
  uStack_3c = param_1[4];
  _uStack_38 = CONCAT22(*(ushort *)((int)param_1 + 0x16),(ushort)*(byte *)(param_1 + 5));
  __ptr = calloc((uint)*(ushort *)((int)param_1 + 0x16),3);
  if (__ptr == (void *)0x0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
  }
  else {
    pvStack_24 = __ptr;
    if (param_2 != (code *)0x0) {
      (*param_2)(0x49,&uStack_44);
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
      *(undefined2 *)((int)pvVar2 + 0xc) = (undefined2)uStack_28;
      __nmemb = (uint)*(ushort *)(param_1[7] + 0xc);
      if (__nmemb != 0) {
        pvVar2 = calloc(__nmemb,4);
        if (pvVar2 == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u24_to_u32(__ptr,__nmemb);
        param_1[8] = free_memory_for_get_sampled_data;
        param_1[9] = param_1[7];
        *(void **)(param_1[7] + 0x10) = pvVar2;
        *(undefined2 *)param_1[7] = (undefined2)uStack_34;
        *(undefined4 *)(param_1[7] + 4) = uStack_30;
        *(undefined1 *)(param_1[7] + 8) = (undefined1)uStack_2c;
        *(undefined2 *)(param_1[7] + 10) = uStack_2c._2_2_;
      }
    }
    free(__ptr);
  }
  return;
}

