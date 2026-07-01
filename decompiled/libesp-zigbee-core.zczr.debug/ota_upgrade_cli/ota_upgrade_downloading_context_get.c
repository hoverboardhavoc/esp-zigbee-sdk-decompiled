/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_context_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ota_upgrade_downloading_context_t * ota_upgrade_downloading_context_get(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  ota_upgrade_downloading_context_t *poVar2;
  
  pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    return (ota_upgrade_downloading_context_t *)pzVar1->data_p;
  }
  poVar2 = (ota_upgrade_downloading_context_t *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                         ,0xd7,"ota_upgrade_downloading_context_get","attr_desc");
  *(poVar2->attr).upgrade_status = '\0';
  *(poVar2->attr).file_offset = 0;
  *(undefined1 *)&(poVar2->file).total_size = 0;
  *(undefined1 *)((int)&(poVar2->file).total_size + 1) = 0;
  *(undefined1 *)((int)&(poVar2->file).total_size + 2) = 0;
  *(undefined1 *)((int)&(poVar2->file).total_size + 3) = 0;
  *(undefined1 *)&(poVar2->file).downloading_version = 0;
  *(undefined1 *)((int)&(poVar2->file).downloading_version + 1) = 0;
  *(undefined1 *)((int)&(poVar2->file).downloading_version + 2) = 0;
  *(undefined1 *)((int)&(poVar2->file).downloading_version + 3) = 0;
  return poVar2;
}

