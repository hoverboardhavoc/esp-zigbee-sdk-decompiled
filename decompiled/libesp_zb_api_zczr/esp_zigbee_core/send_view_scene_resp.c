/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> send_view_scene_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void send_view_scene_resp(undefined4 param_1,int param_2)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  char cVar5;
  
  if ((param_2 == 0xff) || ((&DAT_00018f0e)[param_2 * 6] == -1)) {
    iVar4 = zb_aps_is_endpoint_in_group(DAT_00018ef2,DAT_00018ed8);
    if (iVar4 == 0) {
      cVar5 = -0x7b;
    }
    else {
      cVar5 = -0x75;
    }
  }
  else {
    cVar5 = '\0';
  }
  puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
  *puVar2 = 0x19;
  puVar2[1] = DAT_00018ee1;
  puVar2[2] = 1;
  puVar2[3] = cVar5;
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 4,DAT_00018ef2);
  *puVar2 = DAT_00018ef4;
  puVar3 = puVar2 + 1;
  if (cVar5 == '\0') {
    puVar2[1] = *(undefined1 *)(&DAT_00018f10 + param_2 * 6);
    puVar2[2] = *(undefined1 *)((int)&DAT_00018f10 + param_2 * 0xc + 1);
    puVar2[3] = 0;
    puVar3 = puVar2 + 4;
    for (puVar1 = (undefined2 *)(&DAT_00018f14)[param_2 * 3]; puVar1 != (undefined2 *)0x0;
        puVar1 = *(undefined2 **)(puVar1 + 4)) {
      puVar3 = (undefined1 *)zb_put_next_htole16(*puVar1);
      *puVar3 = *(undefined1 *)(puVar1 + 1);
      iVar4 = 0;
      while( true ) {
        puVar3 = puVar3 + 1;
        if ((int)(uint)*(byte *)(puVar1 + 1) <= iVar4) break;
        *puVar3 = *(undefined1 *)(*(int *)(puVar1 + 2) + iVar4);
        iVar4 = iVar4 + 1;
      }
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,puVar3,&scene_resp_info,2,DAT_00018ed7,DAT_00018ed8,DAT_00018edc >> 8 & 0xffff,
             5);
  return;
}

