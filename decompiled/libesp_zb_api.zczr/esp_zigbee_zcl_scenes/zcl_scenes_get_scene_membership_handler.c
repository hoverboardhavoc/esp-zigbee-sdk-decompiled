/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_get_scene_membership_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_get_scene_membership_handler(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  short sVar3;
  short *psVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  
  iVar5 = zb_buf_get_tail_func(0x38);
  psVar4 = *(short **)(iVar5 + 0x10);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  iVar5 = *(int *)(iVar5 + 0xc);
  if (((psVar4 == (short *)0x0) || (iVar5 == 0)) || (iVar7 = zb_buf_get_out_func(), iVar7 == 0)) {
    uVar6 = 0xffffffff;
  }
  else {
    sVar3 = *psVar4;
    cVar1 = *(char *)(iVar5 + 0xc);
    iVar8 = esp_zb_zcl_scenes_group_check(cVar1,sVar3);
    puVar9 = (undefined1 *)zb_buf_reuse_func(iVar7);
    *puVar9 = 0x19;
    uVar2 = *(undefined1 *)(iVar5 + 0x15);
    puVar9[3] = (char)iVar8;
    puVar9[1] = uVar2;
    puVar9[2] = 6;
    puVar9[4] = -(iVar8 != 0);
    pcVar10 = (char *)zb_put_next_htole16(puVar9 + 5,sVar3);
    pcVar11 = pcVar10;
    if (pcVar10 == (char *)0x0) {
      pcVar10 = (char *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_scenes.c"
                                  ,599);
    }
    if (iVar8 == 0) {
      pcVar12 = &esp_zb_zcl_scenes_table;
      *pcVar10 = '\0';
      pcVar10 = pcVar10 + 1;
      do {
        if ((*pcVar12 == cVar1) && (*(short *)(pcVar12 + 2) == sVar3)) {
          *pcVar11 = *pcVar11 + '\x01';
          *pcVar10 = pcVar12[6];
          pcVar10 = pcVar10 + 1;
        }
        else if (*(short *)(pcVar12 + 2) == -1) {
          puVar9[4] = puVar9[4] + '\x01';
        }
        pcVar12 = pcVar12 + 0xc;
      } while (pcVar12 != (char *)0x1159c);
    }
    zb_zcl_finish_and_send_packet
              (iVar7,pcVar10,iVar5 + 1,2,*(undefined1 *)(iVar5 + 0xb),*(undefined1 *)(iVar5 + 0xc),
               *(undefined2 *)(iVar5 + 0x11),5);
    uVar6 = 0;
  }
  return uVar6;
}

