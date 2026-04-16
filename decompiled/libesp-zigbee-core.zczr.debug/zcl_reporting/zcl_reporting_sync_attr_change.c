/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_sync_attr_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_reporting_sync_attr_change(zcl_reporting_info_t *info)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((info != (zcl_reporting_info_t *)0x0) &&
     (iVar1 = zcl_get_attr_desc(info->ep_id,info->cluster_id,info->cluster_role,info->attr_id,
                                info->manuf_code), iVar1 != 0)) {
    iVar2 = zcl_attr_type_is_analog(*(undefined1 *)(iVar1 + 2));
    if (iVar2 == 0) {
      iVar2 = zcl_get_attr_value_size(*(undefined1 *)(iVar1 + 2),*(undefined4 *)(iVar1 + 8));
      if (iVar2 == 0xffff) {
        *(undefined4 *)((int)&info->u + 0x10) = 0;
      }
      else {
        uVar3 = crc32_next(0,*(undefined4 *)(iVar1 + 8),iVar2);
        *(undefined4 *)((int)&info->u + 0x10) = uVar3;
      }
    }
    else {
      zcl_read_attr_value((undefined1 *)((int)&info->u + 0x10),*(undefined4 *)(iVar1 + 8),
                          *(undefined1 *)(iVar1 + 2));
    }
    info->field_0x9 =
         (byte)((*(uint *)&info->cluster_role >> 0xc & 0xe) << 4) | info->field_0x9 & 0xf;
  }
  return;
}

