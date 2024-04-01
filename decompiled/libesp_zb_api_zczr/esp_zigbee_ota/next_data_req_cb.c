/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> next_data_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int next_data_req_cb(uint param_1,void *param_2,uint param_3,size_t param_4,int *param_5)

{
  code *pcVar1;
  void *__dest;
  uint __n;
  int iVar2;
  undefined1 auStack_70 [36];
  void *pvStack_4c;
  undefined1 auStack_48 [9];
  undefined1 uStack_3f;
  undefined2 uStack_3e;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined1 uStack_36;
  undefined2 uStack_34;
  
  memset(&uStack_3f,0,0xb);
  uStack_3e = *(undefined2 *)((int)param_2 + 9);
  uStack_3c = *(undefined1 *)((int)param_2 + 0xb);
  uStack_3b = *(undefined1 *)((int)param_2 + 0xc);
  uStack_3a = *(undefined2 *)((int)param_2 + 0xf);
  uStack_38 = *(undefined2 *)((int)param_2 + 0x11);
  uStack_36 = *(undefined1 *)((int)param_2 + 0x13);
  uStack_34 = *(undefined2 *)((int)param_2 + 0x19);
  memcpy(auStack_48,param_2,9);
  pcVar1 = s_ota_next_data_cb;
  if (s_ota_server_variable == 0) {
    return -0x1c;
  }
  if (*(byte *)(s_ota_server_variable + 8) <= param_1) {
    return -0x1c;
  }
  iVar2 = *(int *)(*(int *)(s_ota_server_variable + 0xc) + param_1 * 8);
  if (s_ota_next_data_cb == (code *)0x0) {
_L0:
    iVar2 = -1;
  }
  else {
    if (param_4 + param_3 < 0x39) {
      *param_5 = iVar2 + param_3;
      return 0;
    }
    if (param_3 < 0x38) {
      pvStack_4c = (void *)0x0;
      __dest = malloc(param_4);
      memcpy(__dest,(void *)(iVar2 + param_3),0x38 - param_3);
      memcpy(auStack_70,auStack_48,0x16);
      __n = (param_4 + param_3) - 0x38;
      iVar2 = (*pcVar1)(auStack_70,param_1,__n & 0xff,&pvStack_4c);
      if (pvStack_4c == (void *)0x0) goto _L0;
      memcpy((void *)((int)__dest + (0x38 - param_3)),pvStack_4c,__n);
      *param_5 = (int)__dest;
      header_payload_aging_0 = '\x01';
    }
    else {
      if (header_payload_aging_0 != '\0') {
        header_payload_aging_0 = '\0';
      }
      memcpy(auStack_70,auStack_48,0x16);
      iVar2 = (*pcVar1)(auStack_70,param_1,param_4,param_5);
    }
    iVar2 = -(uint)(iVar2 != 0);
  }
  return iVar2;
}

