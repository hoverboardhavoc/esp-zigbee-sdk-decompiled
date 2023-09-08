/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
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
  
  if ((param_2 == 0xff) || ((&esp_zb_zcl_scenes_table)[param_2 * 6] == -1)) {
    iVar4 = zb_aps_is_endpoint_in_group(DAT_000158c6,DAT_000158ac);
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
  puVar2[1] = DAT_000158b5;
  puVar2[2] = 1;
  puVar2[3] = cVar5;
  puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 4,DAT_000158c6);
  *puVar2 = DAT_000158c8;
  puVar3 = puVar2 + 1;
  if (cVar5 == '\0') {
    puVar2[1] = (&DAT_000158e2)[param_2 * 0xc];
    puVar2[2] = (&DAT_000158e3)[param_2 * 0xc];
    puVar2[3] = 0;
    puVar3 = puVar2 + 4;
    for (puVar1 = (undefined2 *)(&DAT_000158e8)[param_2 * 3]; puVar1 != (undefined2 *)0x0;
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
            (param_1,puVar3,&scene_resp_info,2,DAT_000158ab,DAT_000158ac,DAT_000158b0 >> 8 & 0xffff,
             5);
  return;
}

