/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
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
  byte bVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  
  if ((param_2 == 0xff) || ((&esp_zb_zcl_scenes_table)[param_2 * 6] == -1)) {
    iVar4 = zb_aps_is_endpoint_in_group(_DAT_00012c7c,DAT_00012c64);
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
  puVar2[1] = DAT_00012c6c;
  puVar2[2] = 1;
  puVar2[3] = cVar8;
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 4,_DAT_00012c7c);
  *puVar2 = DAT_00012c7e;
  puVar3 = puVar2 + 1;
  if (cVar8 == '\0') {
    puVar2[1] = (&DAT_00012bd6)[param_2 * 0xc];
    puVar2[2] = (&DAT_00012bd7)[param_2 * 0xc];
    puVar2[3] = 0;
    puVar3 = puVar2 + 4;
    puVar1 = (undefined2 *)(&DAT_00012bdc)[param_2 * 3];
    uVar7 = 0;
    bVar5 = 0;
    while( true ) {
      if ((byte)(&DAT_00012bd9)[param_2 * 0xc] <= bVar5) break;
      puVar3 = (undefined1 *)zb_put_next_htole16(*puVar1);
      *puVar3 = *(undefined1 *)(puVar1 + 1);
      for (uVar6 = 0; puVar3 = puVar3 + 1, uVar6 < *(byte *)(puVar1 + 1); uVar6 = uVar6 + 1 & 0xff)
      {
        *puVar3 = *(undefined1 *)(*(int *)(puVar1 + 2) + uVar6);
      }
      bVar5 = *(char *)(uVar7 * 0xc + (&DAT_00012bdc)[param_2 * 3] + 2) + bVar5;
      uVar7 = uVar7 + 1 & 0xff;
      puVar1 = *(undefined2 **)(puVar1 + 4);
    }
  }
  zb_zcl_finish_and_send_packet
            (param_1,puVar3,&scene_resp_info,2,DAT_00012c63,DAT_00012c64,DAT_00012c68,5);
  return;
}

