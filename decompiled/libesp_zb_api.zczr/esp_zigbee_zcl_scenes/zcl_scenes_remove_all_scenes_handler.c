/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_remove_all_scenes_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_all_scenes_handler(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  char cVar3;
  short *psVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  
  iVar6 = zb_buf_get_tail_func(0x38);
  psVar4 = *(short **)(iVar6 + 0x10);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  puVar8 = *(undefined1 **)(iVar6 + 0x14);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  cVar1 = *(char *)(*(int *)(iVar6 + 0xc) + 0xc);
  iVar6 = esp_zb_zcl_scenes_group_check(cVar1,*psVar4);
  *puVar8 = (char)iVar6;
  if (iVar6 == 0) {
    sVar2 = *psVar4;
    cVar3 = '\0';
    for (uVar5 = 0; uVar5 < esp_zb_zcl_scenes_table_capacity; uVar5 = uVar5 + 1 & 0xff) {
      pcVar7 = (char *)(esp_zb_zcl_scenes_table + uVar5 * 0xc);
      if ((*pcVar7 == cVar1) && (*(short *)(pcVar7 + 2) == sVar2)) {
        cVar3 = cVar3 + '\x01';
        device_scenes_table_record_free(uVar5);
      }
    }
    puVar8[1] = cVar3;
  }
  iVar6 = zb_nvram_write_dataset(9);
  return -(uint)(iVar6 != 0);
}

