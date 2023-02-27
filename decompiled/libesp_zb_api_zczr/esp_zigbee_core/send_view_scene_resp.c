/*
 * Last changed at upstream commit b278a1511ed728943e19c371f88a01e9d130f19f
 * https://github.com/espressif/esp-zigbee-sdk/commit/b278a1511ed728943e19c371f88a01e9d130f19f
 * Upstream date: 2023-02-27 14:43:05 +0800
 * Upstream subject: zcl: add ZCL API for color and report attribute(af3fa1e)
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
  byte bVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  
  if ((param_2 == 0xff) || ((&esp_zb_zcl_scenes_table)[param_2 * 6] == -1)) {
    iVar4 = zb_aps_is_endpoint_in_group(scene_resp_info._36_2_,scene_resp_info[0xc]);
    if (iVar4 == 0) {
      cVar8 = -0x7b;
    }
    else {
      cVar8 = -0x75;
    }
  }
  else {
    cVar8 = '\0';
  }
  puVar2 = (undefined1 *)zb_buf_reuse_func(param_1);
  *puVar2 = 0x19;
  puVar2[1] = scene_resp_info[0x14];
  puVar2[2] = 1;
  puVar2[3] = cVar8;
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 4,scene_resp_info._36_2_);
  *puVar2 = scene_resp_info[0x26];
  puVar3 = puVar2 + 1;
  if (cVar8 == '\0') {
    puVar2[1] = (&DAT_0001231e)[param_2 * 0xc];
    puVar2[2] = (&DAT_0001231f)[param_2 * 0xc];
    puVar2[3] = 0;
    puVar3 = puVar2 + 4;
    puVar1 = (undefined2 *)(&DAT_00012324)[param_2 * 3];
    uVar7 = 0;
    bVar5 = 0;
    while( true ) {
      if ((byte)(&DAT_00012321)[param_2 * 0xc] <= bVar5) break;
      puVar3 = (undefined1 *)zb_put_next_htole16(*puVar1);
      *puVar3 = *(undefined1 *)(puVar1 + 1);
      for (uVar6 = 0; puVar3 = puVar3 + 1, uVar6 < *(byte *)(puVar1 + 1); uVar6 = uVar6 + 1 & 0xff)
      {
        *puVar3 = *(undefined1 *)(*(int *)(puVar1 + 2) + uVar6);
      }
      bVar5 = *(char *)(uVar7 * 0xc + (&DAT_00012324)[param_2 * 3] + 2) + bVar5;
      uVar7 = uVar7 + 1 & 0xff;
      puVar1 = *(undefined2 **)(puVar1 + 4);
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,puVar3,0x12395,2,scene_resp_info[0xb],scene_resp_info[0xc],
             scene_resp_info._16_2_,5);
  return;
}

