/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_info_add(zcl_reporting_info_t *info)

{
  uint8_t uVar1;
  uint16_t uVar2;
  int iVar3;
  undefined4 *puVar4;
  zcl_reporting_info_t *info_00;
  ezb_err_t eVar5;
  undefined4 uVar6;
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
  undefined1 auStack_19 [9];
  
  if (info == (zcl_reporting_info_t *)0x0) {
    return 2;
  }
  iVar3 = af_get_ep_desc(info->ep_id);
  if (iVar3 == 0) {
    eVar5 = 5;
  }
  else {
    puVar4 = (undefined4 *)calloc(1,8);
    if (puVar4 != (undefined4 *)0x0) {
      info->next = *(zcl_reporting_info_s **)(iVar3 + 8);
      *(zcl_reporting_info_t **)(iVar3 + 8) = info;
      uVar1 = info->direction;
      *puVar4 = info;
      if (uVar1 == '\0') {
        info->field_0x9 = info->field_0x9 & 0xf0 | 0x11;
      }
      puVar4[1] = puVar4 + 1;
      iVar3 = core_globals_get();
      puVar4[1] = *(undefined4 *)(iVar3 + 0xd34);
      *(undefined4 **)(iVar3 + 0xd34) = puVar4 + 1;
      info_00 = (zcl_reporting_info_t *)*puVar4;
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
        uVar6 = *(undefined4 *)((int)&info_00->u + 0x18);
        uStack_1d = (undefined1)uVar6;
        uStack_1c = (undefined1)((uint)uVar6 >> 8);
        uVar2 = (info_00->u).send_info.def_max_interval;
        uStack_1b = (undefined1)uVar2;
        uStack_1a = (undefined1)(uVar2 >> 8);
        memcpy(auStack_19,(void *)((int)&info_00->u + 8),8);
      }
      eVar5 = ds_internal_add_entry(10,&uStack_2c,0x1b);
      return eVar5;
    }
    eVar5 = 1;
  }
  return eVar5;
}

