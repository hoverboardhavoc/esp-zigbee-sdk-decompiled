/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_ota.o -> next_data_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 next_data_req_cb(uint param_1,void *param_2,uint param_3,size_t param_4,int *param_5)

{
  undefined1 uVar1;
  void *pvVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint __n;
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
  
  pvStack_4c = (void *)0x0;
  memset(&uStack_3f,0,0xb);
  uStack_3e = *(undefined2 *)((int)param_2 + 9);
  uVar1 = *(undefined1 *)((int)param_2 + 0xc);
  uStack_3c = *(undefined1 *)((int)param_2 + 0xb);
  uStack_3a = *(undefined2 *)((int)param_2 + 0xf);
  uStack_38 = *(undefined2 *)((int)param_2 + 0x11);
  uStack_36 = *(undefined1 *)((int)param_2 + 0x13);
  uStack_34 = *(undefined2 *)((int)param_2 + 0x19);
  uStack_3b = uVar1;
  memcpy(auStack_48,param_2,9);
  iVar5 = get_ota_upgrade_server_variables(uVar1);
  pcVar3 = s_ota_next_data_cb;
  if (iVar5 == 0) {
    return 0xffffffe4;
  }
  if (*(byte *)(iVar5 + 8) <= param_1) {
    return 0xffffffe4;
  }
  if (s_ota_next_data_cb == (code *)0x0) {
    return 0xffffffff;
  }
  iVar5 = *(int *)(*(int *)(iVar5 + 0xc) + param_1 * 8);
  uVar4 = (uint)*(ushort *)(iVar5 + 6);
  if (param_4 + param_3 <= uVar4) {
    *param_5 = iVar5 + param_3;
    return 0;
  }
  if (param_3 < uVar4) {
    s_ota_header_payload_0 = malloc(param_4);
    if (s_ota_header_payload_0 == (void *)0x0) {
      return 0xffffffff;
    }
    memcpy(s_ota_header_payload_0,(void *)(iVar5 + param_3),uVar4 - param_3);
    memcpy(auStack_70,auStack_48,0x16);
    __n = (param_4 + param_3) - uVar4;
    iVar5 = (*pcVar3)(auStack_70,param_1,__n & 0xff,&pvStack_4c);
    pvVar2 = s_ota_header_payload_0;
    if (pvStack_4c == (void *)0x0) goto _L0;
    memcpy((void *)((int)s_ota_header_payload_0 + (uVar4 - param_3)),pvStack_4c,__n);
    *param_5 = (int)pvVar2;
  }
  else {
    if (s_ota_header_payload_0 != (void *)0x0) {
      free(s_ota_header_payload_0);
      s_ota_header_payload_0 = (void *)0x0;
    }
    memcpy(auStack_70,auStack_48,0x16);
    iVar5 = (*pcVar3)(auStack_70,param_1,param_4,param_5);
    if (*param_5 == 0) goto _L0;
  }
  if (iVar5 == 0) {
    return 0;
  }
_L0:
  if (s_ota_header_payload_0 != (void *)0x0) {
    free(s_ota_header_payload_0);
    s_ota_header_payload_0 = (void *)0x0;
  }
  return 0xffffffff;
}

