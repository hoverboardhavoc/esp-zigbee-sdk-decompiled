/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
           __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0xd4,
                         "ota_upgrade_downloading_context_get","attr_desc");
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

