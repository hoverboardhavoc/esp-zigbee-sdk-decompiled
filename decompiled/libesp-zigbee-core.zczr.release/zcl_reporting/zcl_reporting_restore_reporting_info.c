/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_restore_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: itor */
/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_restore_reporting_info(uint8_t ep_id)

{
  uint8_t uVar1;
  int *piVar2;
  undefined3 in_register_00002029;
  zcl_reporting_info_t *pzVar3;
  ezb_err_t eVar4;
  int iVar5;
  ezb_err_t eVar6;
  undefined1 local_30 [4];
  ds_zcl_reporting_info_iterator_t itor;
  
  memset(local_30,0,0x20);
  do {
    ds_zcl_reporting_info_itor_read((ds_zcl_reporting_info_iterator_t *)local_30);
    do {
      uVar1 = local_30[0];
      if (itor.data.field_7.send_info.delta._7_1_ != '\0') {
        return 0;
      }
      if ((uint)local_30[1] != CONCAT31(in_register_00002029,ep_id)) break;
      pzVar3 = zcl_reporting_info_create
                         (ep_id,local_30._2_2_,local_30[0] != '\0',itor.data._0_2_,
                          (uint8_t)itor.data.profile_id,
                          (ushort)itor.data.profile_id._1_1_ |
                          (ushort)((itor.data._4_4_ & 0xff) << 8),SUB42(itor.data._4_4_,1));
      if (pzVar3 == (zcl_reporting_info_t *)0x0) {
        eVar4 = 1;
_L0:
        ds_internal_remove_entry(10,0xffffffff,0);
        iVar5 = core_globals_get();
        piVar2 = *(int **)(iVar5 + 0xd98);
        while ((piVar2 + -1 != (undefined4 *)0xfffffffc &&
               ((pzVar3 = (zcl_reporting_info_t *)piVar2[-1], pzVar3 == (zcl_reporting_info_t *)0x0
                || (eVar6 = zcl_reporting_store_reporting_info(pzVar3), eVar6 == 0))))) {
          piVar2 = (int *)*piVar2;
        }
        return eVar4;
      }
      (pzVar3->u).send_info.min_interval =
           CONCAT11(itor.data.attr_id._1_1_,(undefined1)itor.data.attr_id);
      if (uVar1 == '\0') {
        (pzVar3->u).send_info.max_interval = itor.data.manuf_code;
        (pzVar3->u).send_info.def_min_interval =
             CONCAT11(itor.data.field_7.send_info.min_interval._1_1_,
                      itor.data.field_7.send_info.min_interval._0_1_);
        (pzVar3->u).send_info.def_max_interval = (uint16_t)((uint)itor.data.field_7._1_4_ >> 8);
        memcpy((void *)((int)&pzVar3->u + 8),(void *)((int)&itor.data.field_7 + 4),8);
      }
      eVar4 = zcl_reporting_info_add(pzVar3);
      if (eVar4 != 0) {
        eVar4 = -1;
        goto _L0;
      }
    } while (itor.data.field_7.send_info.delta._7_1_ != '\0');
    itor.data.field_7.send_info.delta._5_2_ = itor.data.field_7.send_info.delta._5_2_ + 1;
  } while( true );
}

