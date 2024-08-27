/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ota.o -> esp_zb_ota_upgrade_server_notify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ota_upgrade_server_notify_req(undefined1 *param_1)

{
  int iVar1;
  void *__ptr;
  undefined1 *puVar2;
  undefined4 uVar3;
  void *__ptr_00;
  
  iVar1 = get_ota_upgrade_server_variables(*param_1);
  if ((iVar1 == 0) || ((uint)*(byte *)(iVar1 + 8) <= (uint)(byte)param_1[1])) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x100c4,&_LC8,uVar3,0x100c4,"esp_zb_ota_upgrade_server_notify_req",0xb7,
                  *(byte *)(iVar1 + 8) - 1);
    iVar1 = 0x102;
  }
  else if (*(int *)(param_1 + 0x24) == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x100c4,&_LC9,uVar3,0x100c4,"esp_zb_ota_upgrade_server_notify_req",0xb9);
    iVar1 = 0x102;
  }
  else {
    __ptr_00 = *(void **)((uint)(byte)param_1[1] * 8 + *(int *)(iVar1 + 0xc));
    __ptr = (void *)zb_zcl_create_ota_upgrade_header(param_1 + 8);
    s_ota_next_data_cb = *(undefined4 *)(param_1 + 0x24);
    iVar1 = zb_zcl_get_ctx();
    *(code **)(iVar1 + 0xb8) = next_data_req_cb;
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x100c4,&_LC10,uVar3,0x100c4,"esp_zb_ota_upgrade_server_notify_req",0xc1);
      iVar1 = 0x102;
    }
    else {
      puVar2 = (undefined1 *)zb_buf_get_tail_func(0x10);
      *puVar2 = *param_1;
      puVar2[1] = param_1[1];
      *(void **)(puVar2 + 4) = __ptr;
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 4);
      puVar2[8] = param_1[2];
      iVar1 = zb_zcl_ota_upgrade_insert_file(iVar1);
      if (iVar1 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x100c4,&_LC11,uVar3,0x100c4,"esp_zb_ota_upgrade_server_notify_req",0xc4,
                      param_1[1]);
        iVar1 = 0x102;
      }
    }
    if ((__ptr != (void *)0x0) && (iVar1 != 0)) {
      free(__ptr);
    }
    if ((__ptr_00 != (void *)0x0) && (__ptr_00 != __ptr)) {
      free(__ptr_00);
    }
  }
  return iVar1;
}

