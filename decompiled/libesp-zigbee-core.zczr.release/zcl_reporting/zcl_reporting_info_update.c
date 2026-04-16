/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_info_update(zcl_reporting_info_t *info)

{
  byte bVar1;
  uint16_t uVar2;
  ezb_err_t eVar3;
  zcl_reporting_info_t *info_00;
  undefined4 uVar4;
  undefined4 uStack_2c;
  uint16_t uStack_28;
  uint8_t uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 auStack_19 [13];
  
  info_00 = zcl_reporting_info_find
                      (info->ep_id,info->cluster_id,info->cluster_role,info->attr_id,
                       info->manuf_code);
  if (info_00 == (zcl_reporting_info_t *)0x0) {
    return 5;
  }
  if (info_00->direction == '\0') {
    memcpy(info_00,info,0x34);
    if (*(int *)&info->u == 0xffff) {
      *(undefined4 *)&info_00->u = *(undefined4 *)((int)&info_00->u + 0x18);
      memset((void *)((int)&info_00->u + 8),0,8);
    }
    bVar1 = info_00->field_0x9;
    info_00->field_0x9 = bVar1 | 0x40;
    if ((bVar1 & 0xf) != 4) {
      info_00->field_0x9 = bVar1 & 0xf0 | 0x43;
    }
  }
  else {
    (info_00->u).send_info.min_interval = (info->u).send_info.min_interval;
  }
  process_attr_report(info_00);
  memset(&uStack_2c,0,0x1b);
  zcl_reporting_remove_stored_reporting_info(info_00);
  uStack_28 = info_00->cluster_id;
  uStack_2c._0_1_ = info_00->direction;
  uStack_2c._1_1_ = info_00->ep_id;
  uStack_2c._2_2_ = info_00->profile_id;
  uStack_26 = info_00->cluster_role;
  uStack_25 = (undefined1)info_00->attr_id;
  uStack_24 = (undefined1)(info_00->attr_id >> 8);
  uStack_23 = (undefined1)*(undefined4 *)&info_00->manuf_code;
  uStack_22 = (undefined1)((uint)*(undefined4 *)&info_00->manuf_code >> 8);
  uVar2 = (info_00->u).send_info.min_interval;
  uStack_21 = (undefined1)uVar2;
  uStack_20 = (undefined1)(uVar2 >> 8);
  if (info_00->direction == '\0') {
    uVar2 = (info_00->u).send_info.max_interval;
    uStack_1f = (undefined1)uVar2;
    uStack_1e = (undefined1)(uVar2 >> 8);
    uVar4 = *(undefined4 *)((int)&info_00->u + 0x18);
    uStack_1d = (undefined1)uVar4;
    uStack_1c = (undefined1)((uint)uVar4 >> 8);
    uVar2 = (info_00->u).send_info.def_max_interval;
    uStack_1b = (undefined1)uVar2;
    uStack_1a = (undefined1)(uVar2 >> 8);
    memcpy(auStack_19,(void *)((int)&info_00->u + 8),8);
  }
  eVar3 = ds_internal_add_entry(10,&uStack_2c,0x1b);
  return eVar3;
}

