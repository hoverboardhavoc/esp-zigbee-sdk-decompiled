/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_ota.o -> next_data_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int next_data_req_cb(uint param_1,undefined4 *param_2,uint param_3,size_t param_4,int *param_5)

{
  void *pvVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined2 uStack_38;
  void *apvStack_34 [3];
  
  apvStack_34[0] = (void *)0x0;
  iStack_44 = (uint)*(ushort *)((int)param_2 + 9) << 0x10;
  uStack_40 = CONCAT22(*(undefined2 *)((int)param_2 + 0xf),*(undefined2 *)((int)param_2 + 0xb));
  uStack_3c = (uint)*(uint3 *)((int)param_2 + 0x11);
  uStack_38 = *(undefined2 *)((int)param_2 + 0x19);
  uStack_4c = *param_2;
  uStack_48 = param_2[1];
  iStack_44 = CONCAT31(iStack_44._1_3_,*(undefined1 *)(param_2 + 2));
  iVar4 = get_ota_upgrade_server_variables();
  pcVar2 = s_ota_next_data_cb;
  if ((iVar4 == 0) || (*(byte *)(iVar4 + 8) <= param_1)) {
    uVar5 = esp_log_timestamp();
    esp_log(1,0x100c4,"E (%lu) %s: %s(%d): Failed to find index[%d] OTA file\n",uVar5,0x100c4,
            "next_data_req_cb",0x51,param_1);
    return -0x1c;
  }
  if (s_ota_next_data_cb == (code *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log(1,0x100c4,"E (%lu) %s: %s(%d): Failed to find OTA next data callback\n",uVar5,0x100c4,
            "next_data_req_cb",0x53);
    return -1;
  }
  iVar4 = *(int *)(*(int *)(iVar4 + 0xc) + param_1 * 8);
  uVar3 = (uint)*(ushort *)(iVar4 + 6);
  if (param_4 + param_3 <= uVar3) {
    *param_5 = iVar4 + param_3;
    iVar4 = 0;
    goto _L0;
  }
  if (param_3 < uVar3) {
    s_ota_header_payload_1 = malloc(param_4);
    if (s_ota_header_payload_1 == (void *)0x0) {
      uVar5 = esp_log_timestamp();
      esp_log(1,0x100c4,"E (%lu) %s: %s(%d): No memory for OTA image block\n",uVar5,0x100c4,
              "next_data_req_cb",0x5d);
      return -1;
    }
    memcpy(s_ota_header_payload_1,(void *)(iVar4 + param_3),uVar3 - param_3);
    local_70 = uStack_4c;
    uStack_6c = uStack_48;
    uStack_68 = iStack_44;
    uStack_64 = uStack_40;
    uStack_60 = uStack_3c;
    uStack_5c = uStack_38;
    iVar4 = (*pcVar2)(&local_70,param_1,(param_4 + param_3 & 0xff) - uVar3 & 0xff,apvStack_34);
    pvVar1 = s_ota_header_payload_1;
    if (apvStack_34[0] != (void *)0x0) {
      memcpy((void *)((int)s_ota_header_payload_1 + (uVar3 - param_3)),apvStack_34[0],
             (param_4 + param_3) - uVar3);
      *param_5 = (int)pvVar1;
      goto _L0;
    }
    uVar5 = esp_log_timestamp();
    esp_log(1,0x100c4,"E (%lu) %s: %s(%d): Invalid OTA data\n",uVar5,0x100c4,"next_data_req_cb",0x61
           );
    iVar4 = 0x101;
  }
  else {
    if (s_ota_header_payload_1 != (void *)0x0) {
      free(s_ota_header_payload_1);
      s_ota_header_payload_1 = (void *)0x0;
    }
    local_70 = uStack_4c;
    uStack_6c = uStack_48;
    uStack_68 = iStack_44;
    uStack_64 = uStack_40;
    uStack_60 = uStack_3c;
    uStack_5c = uStack_38;
    iVar4 = (*pcVar2)(&local_70,param_1,param_4,param_5);
    if (*param_5 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log(1,0x100c4,"E (%lu) %s: %s(%d): Invalid OTA data\n",uVar5,0x100c4,"next_data_req_cb",
              0x6b);
      iVar4 = 0x101;
    }
    else {
_L0:
      if (iVar4 == 0) {
        return 0;
      }
    }
  }
  if (s_ota_header_payload_1 != (void *)0x0) {
    free(s_ota_header_payload_1);
    s_ota_header_payload_1 = (void *)0x0;
  }
_L0:
  if (iVar4 != 0) {
    iVar4 = -1;
  }
  return iVar4;
}

