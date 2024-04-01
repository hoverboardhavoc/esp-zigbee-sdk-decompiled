/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ota.o -> next_data_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int next_data_req_cb(uint param_1,undefined4 *param_2,uint param_3,size_t param_4,int *param_5)

{
  code *pcVar1;
  void *__dest;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined2 uStack_5c;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined2 uStack_34;
  
  pcVar1 = s_ota_next_data_cb;
  iStack_40 = (uint)*(ushort *)((int)param_2 + 9) << 0x10;
  uStack_3c = CONCAT22(*(undefined2 *)((int)param_2 + 0xf),*(undefined2 *)((int)param_2 + 0xb));
  uStack_38 = (uint)*(uint3 *)((int)param_2 + 0x11);
  uStack_5c = *(undefined2 *)((int)param_2 + 0x19);
  local_70 = *param_2;
  uStack_6c = param_2[1];
  iStack_40 = CONCAT31(iStack_40._1_3_,*(undefined1 *)(param_2 + 2));
  uStack_48 = local_70;
  uStack_44 = uStack_6c;
  uStack_34 = uStack_5c;
  if (s_ota_server_variable == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar2,0x10000,"next_data_req_cb",0x47);
    iVar3 = -0x1c;
  }
  else if (param_1 < *(byte *)(s_ota_server_variable + 8)) {
    iVar3 = *(int *)(*(int *)(s_ota_server_variable + 0xc) + param_1 * 8);
    if (s_ota_next_data_cb == (code *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar2,0x10000,"next_data_req_cb",0x4a);
      iVar3 = -1;
    }
    else if (param_3 + param_4 < 0x39) {
      *param_5 = iVar3 + param_3;
      iVar3 = 0;
    }
    else {
      if (param_3 < 0x38) {
        pvStack_4c = (void *)0x0;
        __dest = malloc(param_4);
        memcpy(__dest,(void *)(iVar3 + param_3),0x38 - param_3);
        local_70 = uStack_48;
        uStack_6c = uStack_44;
        uStack_68 = iStack_40;
        uStack_64 = uStack_3c;
        uStack_60 = uStack_38;
        uStack_5c = uStack_34;
        iVar3 = (*pcVar1)(&local_70,param_1,(param_4 + param_3 & 0xff) - 0x38 & 0xff,&pvStack_4c);
        if (pvStack_4c == (void *)0x0) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC4,uVar2,0x10000,"next_data_req_cb",0x53);
          return -1;
        }
        memcpy((void *)((int)__dest + (0x38 - param_3)),pvStack_4c,(param_3 + param_4) - 0x38);
        *param_5 = (int)__dest;
        header_payload_aging_0 = '\x01';
      }
      else {
        if (header_payload_aging_0 != '\0') {
          header_payload_aging_0 = '\0';
        }
        uStack_68 = iStack_40;
        uStack_64 = uStack_3c;
        uStack_60 = uStack_38;
        iVar3 = (*s_ota_next_data_cb)(&local_70,param_1,param_4,param_5);
      }
      if (iVar3 != 0) {
        iVar3 = -1;
      }
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar2,0x10000,"next_data_req_cb",0x48,param_1);
    iVar3 = -0x1c;
  }
  return iVar3;
}

