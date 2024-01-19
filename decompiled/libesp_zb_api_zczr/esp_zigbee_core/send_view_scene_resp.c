/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
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
  
  if ((param_2 == 0xff) || ((&DAT_00017822)[param_2 * 6] == -1)) {
    iVar4 = zb_aps_is_endpoint_in_group(DAT_00017806,DAT_000177ec);
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
  puVar2[1] = DAT_000177f5;
  puVar2[2] = 1;
  puVar2[3] = cVar5;
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 4,DAT_00017806);
  *puVar2 = DAT_00017808;
  puVar3 = puVar2 + 1;
  if (cVar5 == '\0') {
    puVar2[1] = (&DAT_00017824)[param_2 * 0xc];
    puVar2[2] = (&DAT_00017825)[param_2 * 0xc];
    puVar2[3] = 0;
    puVar3 = puVar2 + 4;
    for (puVar1 = (undefined2 *)(&DAT_00017828)[param_2 * 3]; puVar1 != (undefined2 *)0x0;
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
            (param_1,puVar3,&scene_resp_info,2,DAT_000177eb,DAT_000177ec,DAT_000177f0 >> 8 & 0xffff,
             5);
  return;
}

