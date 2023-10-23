/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> send_view_scene_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void send_view_scene_resp(undefined4 param_1,int param_2)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  char cVar5;
  
  if ((param_2 == 0xff) || (*(short *)(&esp_zb_zcl_scenes_table + param_2 * 0xc) == -1)) {
    iVar4 = zb_aps_is_endpoint_in_group(_DAT_00015ab2,DAT_00015a98);
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
  puVar2[1] = DAT_00015aa1;
  puVar2[2] = 1;
  puVar2[3] = cVar5;
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 4,_DAT_00015ab2);
  *puVar2 = DAT_00015ab4;
  puVar3 = puVar2 + 1;
  if (cVar5 == '\0') {
    puVar2[1] = (&DAT_00015ace)[param_2 * 0xc];
    puVar2[2] = (&DAT_00015acf)[param_2 * 0xc];
    puVar2[3] = 0;
    puVar3 = puVar2 + 4;
    for (puVar1 = (undefined2 *)(&DAT_00015ad4)[param_2 * 3]; puVar1 != (undefined2 *)0x0;
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
            (param_1,puVar3,&scene_resp_info,2,DAT_00015a97,DAT_00015a98,_DAT_00015a9c >> 8 & 0xffff
             ,5);
  return;
}

