/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> send_view_scene_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void send_view_scene_resp(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  
  if (param_2 != 0xff) {
    cVar6 = '\0';
    if ((&DAT_00015ba2)[param_2 * 6] != -1) goto _L0;
  }
  cVar6 = -0x7b;
  iVar3 = zb_aps_is_endpoint_in_group(DAT_00015b86,DAT_00015b6c);
  if (iVar3 != 0) {
    cVar6 = -0x75;
  }
_L0:
  puVar4 = (undefined1 *)zb_buf_reuse_func(param_1);
  *puVar4 = 0x19;
  uVar1 = DAT_00015b75;
  puVar4[3] = cVar6;
  puVar4[1] = uVar1;
  puVar4[2] = 1;
  puVar4 = (undefined1 *)zb_put_next_htole16(DAT_00015b86);
  puVar5 = puVar4 + 1;
  *puVar4 = DAT_00015b88;
  if (cVar6 == '\0') {
    puVar4[1] = *(undefined1 *)(&DAT_00015ba4 + param_2 * 6);
    puVar4[2] = *(undefined1 *)((int)&DAT_00015ba4 + param_2 * 0xc + 1);
    puVar4[3] = 0;
    puVar5 = puVar4 + 4;
    for (puVar2 = (undefined2 *)(&DAT_00015ba8)[param_2 * 3]; puVar2 != (undefined2 *)0x0;
        puVar2 = *(undefined2 **)(puVar2 + 4)) {
      puVar5 = (undefined1 *)zb_put_next_htole16(*puVar2);
      *puVar5 = *(undefined1 *)(puVar2 + 1);
      iVar3 = 0;
      while( true ) {
        puVar5 = puVar5 + 1;
        if ((int)(uint)*(byte *)(puVar2 + 1) <= iVar3) break;
        puVar4 = (undefined1 *)(*(int *)(puVar2 + 2) + iVar3);
        iVar3 = iVar3 + 1;
        *puVar5 = *puVar4;
      }
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,puVar5,&scene_resp_info,2,DAT_00015b6b,DAT_00015b6c,DAT_00015b70 >> 8 & 0xffff,
             5);
  return;
}

