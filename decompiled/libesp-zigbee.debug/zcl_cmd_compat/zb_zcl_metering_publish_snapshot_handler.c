/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_publish_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_metering_publish_snapshot_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  byte bVar1;
  ezb_zcl_status_t eVar2;
  esp_zb_uint48_t *dst;
  esp_zb_uint48_t *peVar3;
  esp_err_t err;
  uint64_t *puVar4;
  esp_zb_uint48_t *peVar5;
  uint uVar6;
  undefined4 uStack_58;
  esp_zb_zcl_metering_publish_snapshot_message_t app_message;
  
  app_message._20_4_ = 0;
  app_message.snapshot_sub_payload._3_4_ = 0;
  app_message.snapshot_sub_payload.tou_delivered_no_billing.tier_summation = (esp_zb_uint48_t *)0x0;
  app_message.snapshot_sub_payload._11_4_ = 0;
  app_message.snapshot_sub_payload._15_4_ = 0;
  app_message.snapshot_sub_payload._19_4_ = 0;
  app_message.snapshot_sub_payload._23_4_ = 0;
  app_message.snapshot_sub_payload._27_4_ = 0;
                    /* WARNING: Load size is inaccurate */
  uStack_58 = *arg;
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0x10);
  app_message.snapshot_id = *(uint32_t *)((int)arg + 0x14);
  app_message.snapshot_time = (uint32_t)*(uint3 *)((int)arg + 0x18);
  app_message._12_4_ = *(undefined4 *)((int)arg + 0x1c);
  bVar1 = *(byte *)((int)arg + 0x20);
  app_message.snapshot_cause = (uint32_t)bVar1;
  if (bVar1 == 4) {
    array_copy_u64_to_u48
              ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
               (uint64_t *)((int)arg + 0x28),1);
    uVar6 = (uint)*(byte *)((int)arg + 0x30);
    app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
         *(byte *)((int)arg + 0x30);
    if (uVar6 == 0) {
      peVar5 = (esp_zb_uint48_t *)0x0;
      dst = (esp_zb_uint48_t *)0x0;
    }
    else {
      puVar4 = *(uint64_t **)((int)arg + 0x34);
      if (puVar4 == (uint64_t *)0x0) {
        dst = (esp_zb_uint48_t *)0x0;
        peVar5 = (esp_zb_uint48_t *)0x0;
      }
      else {
        dst = (esp_zb_uint48_t *)calloc(uVar6,6);
        if (dst == (esp_zb_uint48_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(dst,puVar4,uVar6);
        peVar5 = (esp_zb_uint48_t *)0x0;
        app_message.snapshot_sub_payload._3_4_ = dst;
      }
    }
  }
  else if (bVar1 < 5) {
    if (bVar1 == 2) {
      array_copy_u64_to_u48
                ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                 (uint64_t *)((int)arg + 0x28),1);
      app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
           (char)*(undefined4 *)((int)arg + 0x30);
      app_message.snapshot_sub_payload._3_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x30) >> 8);
      app_message.snapshot_sub_payload.tou_delivered_no_billing.number_of_tiers_in_use =
           (char)*(undefined4 *)((int)arg + 0x34);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x34) >> 8);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
           (char)*(undefined4 *)((int)arg + 0x38);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._1_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x38) >> 8);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._0_1_ =
           (char)*(undefined4 *)((int)arg + 0x3c);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._1_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x3c) >> 8);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._0_1_ =
           *(undefined1 *)((int)arg + 0x40);
      uVar6 = (uint)*(byte *)((int)arg + 0x41);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._1_1_ =
           *(byte *)((int)arg + 0x41);
      if (uVar6 == 0) {
        dst = (esp_zb_uint48_t *)0x0;
      }
      else {
        peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x44);
        dst = peVar5;
        if (peVar5 != (esp_zb_uint48_t *)0x0) {
          dst = (esp_zb_uint48_t *)calloc(uVar6,6);
          if (dst == (esp_zb_uint48_t *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(dst,(uint64_t *)peVar5,uVar6);
          app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._2_1_ =
               (char)dst;
          app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._3_1_ =
               (char)((uint)dst >> 8);
          app_message.snapshot_sub_payload.tou_delivered.bill_delivered_trailing_digit =
               (char)((uint)dst >> 0x10);
          app_message.snapshot_sub_payload.tou_delivered.number_of_tiers_in_use =
               (char)((uint)dst >> 0x18);
        }
      }
      uVar6 = (uint)*(byte *)((int)arg + 0x48);
      app_message.snapshot_sub_payload._24_1_ = *(byte *)((int)arg + 0x48);
      if (uVar6 == 0) {
        peVar5 = (esp_zb_uint48_t *)0x0;
      }
      else {
        peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x4c);
        if (peVar5 != (esp_zb_uint48_t *)0x0) {
          peVar3 = (esp_zb_uint48_t *)calloc(uVar6,6);
          if (peVar3 == (esp_zb_uint48_t *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(peVar3,(uint64_t *)peVar5,uVar6);
          app_message.snapshot_sub_payload._25_2_ = (short)peVar3;
          app_message.snapshot_sub_payload._27_2_ = (short)((uint)peVar3 >> 0x10);
          peVar5 = peVar3;
        }
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        array_copy_u64_to_u48
                  ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                   (uint64_t *)((int)arg + 0x28),1);
        app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
             (char)*(undefined4 *)((int)arg + 0x30);
        app_message.snapshot_sub_payload._3_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x30) >> 8);
        app_message.snapshot_sub_payload.tou_delivered_no_billing.number_of_tiers_in_use =
             (char)*(undefined4 *)((int)arg + 0x34);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x34) >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
             (char)*(undefined4 *)((int)arg + 0x38);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._1_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x38) >> 8);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._0_1_ =
             (char)*(undefined4 *)((int)arg + 0x3c);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._1_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x3c) >> 8);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._0_1_ =
             *(undefined1 *)((int)arg + 0x40);
        uVar6 = (uint)*(byte *)((int)arg + 0x41);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._1_1_ =
             *(byte *)((int)arg + 0x41);
        if (uVar6 == 0) {
          dst = (esp_zb_uint48_t *)0x0;
          peVar5 = (esp_zb_uint48_t *)0x0;
        }
        else {
          puVar4 = *(uint64_t **)((int)arg + 0x44);
          if (puVar4 == (uint64_t *)0x0) {
            dst = (esp_zb_uint48_t *)0x0;
            peVar5 = (esp_zb_uint48_t *)0x0;
          }
          else {
            dst = (esp_zb_uint48_t *)calloc(uVar6,6);
            if (dst == (esp_zb_uint48_t *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u64_to_u48(dst,puVar4,uVar6);
            app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._2_1_
                 = (char)dst;
            app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._3_1_
                 = (char)((uint)dst >> 8);
            app_message.snapshot_sub_payload.tou_delivered.bill_delivered_trailing_digit =
                 (char)((uint)dst >> 0x10);
            app_message.snapshot_sub_payload.tou_delivered.number_of_tiers_in_use =
                 (char)((uint)dst >> 0x18);
            peVar5 = (esp_zb_uint48_t *)0x0;
          }
        }
      }
      else {
        if (bVar1 != 1) goto _L0;
        array_copy_u64_to_u48
                  ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                   (uint64_t *)((int)arg + 0x28),1);
        app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
             (char)*(undefined4 *)((int)arg + 0x30);
        app_message.snapshot_sub_payload._3_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x30) >> 8);
        app_message.snapshot_sub_payload.tou_delivered_no_billing.number_of_tiers_in_use =
             (char)*(undefined4 *)((int)arg + 0x34);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x34) >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
             (char)*(undefined4 *)((int)arg + 0x38);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._1_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x38) >> 8);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._0_1_ =
             (char)*(undefined4 *)((int)arg + 0x3c);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._1_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x3c) >> 8);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._0_1_ =
             *(undefined1 *)((int)arg + 0x40);
        uVar6 = (uint)*(byte *)((int)arg + 0x41);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._1_1_ =
             *(byte *)((int)arg + 0x41);
        if (uVar6 == 0) {
          dst = (esp_zb_uint48_t *)0x0;
          peVar5 = (esp_zb_uint48_t *)0x0;
        }
        else {
          puVar4 = *(uint64_t **)((int)arg + 0x44);
          if (puVar4 == (uint64_t *)0x0) {
            dst = (esp_zb_uint48_t *)0x0;
            peVar5 = (esp_zb_uint48_t *)0x0;
          }
          else {
            dst = (esp_zb_uint48_t *)calloc(uVar6,6);
            if (dst == (esp_zb_uint48_t *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u64_to_u48(dst,puVar4,uVar6);
            app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._2_1_
                 = (char)dst;
            app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._3_1_
                 = (char)((uint)dst >> 8);
            app_message.snapshot_sub_payload.tou_delivered.bill_delivered_trailing_digit =
                 (char)((uint)dst >> 0x10);
            app_message.snapshot_sub_payload.tou_delivered.number_of_tiers_in_use =
                 (char)((uint)dst >> 0x18);
            peVar5 = (esp_zb_uint48_t *)0x0;
          }
        }
      }
    }
    else {
      if (bVar1 != 3) {
_L0:
        *(undefined1 *)((int)arg + 0x50) = 0x87;
        return;
      }
      array_copy_u64_to_u48
                ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                 (uint64_t *)((int)arg + 0x28),1);
      app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
           (char)*(undefined4 *)((int)arg + 0x30);
      app_message.snapshot_sub_payload._3_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x30) >> 8);
      app_message.snapshot_sub_payload.tou_delivered_no_billing.number_of_tiers_in_use =
           (char)*(undefined4 *)((int)arg + 0x34);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x34) >> 8);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
           (char)*(undefined4 *)((int)arg + 0x38);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._1_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x38) >> 8);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._0_1_ =
           (char)*(undefined4 *)((int)arg + 0x3c);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._1_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x3c) >> 8);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._0_1_ =
           *(undefined1 *)((int)arg + 0x40);
      uVar6 = (uint)*(byte *)((int)arg + 0x41);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._1_1_ =
           *(byte *)((int)arg + 0x41);
      if (uVar6 == 0) {
        dst = (esp_zb_uint48_t *)0x0;
      }
      else {
        peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x44);
        dst = peVar5;
        if (peVar5 != (esp_zb_uint48_t *)0x0) {
          dst = (esp_zb_uint48_t *)calloc(uVar6,6);
          if (dst == (esp_zb_uint48_t *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(dst,(uint64_t *)peVar5,uVar6);
          app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._2_1_ =
               (char)dst;
          app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._3_1_ =
               (char)((uint)dst >> 8);
          app_message.snapshot_sub_payload.tou_delivered.bill_delivered_trailing_digit =
               (char)((uint)dst >> 0x10);
          app_message.snapshot_sub_payload.tou_delivered.number_of_tiers_in_use =
               (char)((uint)dst >> 0x18);
        }
      }
      uVar6 = (uint)*(byte *)((int)arg + 0x48);
      app_message.snapshot_sub_payload._24_1_ = *(byte *)((int)arg + 0x48);
      if (uVar6 == 0) {
        peVar5 = (esp_zb_uint48_t *)0x0;
      }
      else {
        peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x4c);
        if (peVar5 != (esp_zb_uint48_t *)0x0) {
          peVar3 = (esp_zb_uint48_t *)calloc(uVar6,6);
          if (peVar3 == (esp_zb_uint48_t *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(peVar3,(uint64_t *)peVar5,uVar6);
          app_message.snapshot_sub_payload._25_2_ = (short)peVar3;
          app_message.snapshot_sub_payload._27_2_ = (short)((uint)peVar3 >> 0x10);
          peVar5 = peVar3;
        }
      }
    }
  }
  else if (bVar1 == 6) {
    array_copy_u64_to_u48
              ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
               (uint64_t *)((int)arg + 0x28),1);
    uVar6 = (uint)*(byte *)((int)arg + 0x30);
    app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
         *(byte *)((int)arg + 0x30);
    if (uVar6 == 0) {
      dst = (esp_zb_uint48_t *)0x0;
    }
    else {
      peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x34);
      dst = peVar5;
      if (peVar5 != (esp_zb_uint48_t *)0x0) {
        dst = (esp_zb_uint48_t *)calloc(uVar6,6);
        if (dst == (esp_zb_uint48_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(dst,(uint64_t *)peVar5,uVar6);
        app_message.snapshot_sub_payload._3_4_ = dst;
      }
    }
    uVar6 = (uint)*(byte *)((int)arg + 0x38);
    app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_1_ =
         *(byte *)((int)arg + 0x38);
    if (uVar6 == 0) {
      peVar5 = (esp_zb_uint48_t *)0x0;
    }
    else {
      peVar3 = *(esp_zb_uint48_t **)((int)arg + 0x3c);
      peVar5 = peVar3;
      if (peVar3 != (esp_zb_uint48_t *)0x0) {
        peVar5 = (esp_zb_uint48_t *)calloc(uVar6,6);
        if (peVar5 == (esp_zb_uint48_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(peVar5,(uint64_t *)peVar3,uVar6);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._2_1_ = (char)peVar5;
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._3_1_ =
             (char)((uint)peVar5 >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
             (char)((uint)peVar5 >> 0x10);
        app_message.snapshot_sub_payload.block_tier_delivered_no_billing.
        number_of_tiers_and_block_thresholds_in_use = (char)((uint)peVar5 >> 0x18);
      }
    }
  }
  else if (bVar1 == 7) {
    array_copy_u64_to_u48
              ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
               (uint64_t *)((int)arg + 0x28),1);
    uVar6 = (uint)*(byte *)((int)arg + 0x30);
    app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
         *(byte *)((int)arg + 0x30);
    if (uVar6 == 0) {
      dst = (esp_zb_uint48_t *)0x0;
    }
    else {
      peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x34);
      dst = peVar5;
      if (peVar5 != (esp_zb_uint48_t *)0x0) {
        dst = (esp_zb_uint48_t *)calloc(uVar6,6);
        if (dst == (esp_zb_uint48_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(dst,(uint64_t *)peVar5,uVar6);
        app_message.snapshot_sub_payload._3_4_ = dst;
      }
    }
    uVar6 = (uint)*(byte *)((int)arg + 0x38);
    app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_1_ =
         *(byte *)((int)arg + 0x38);
    if (uVar6 == 0) {
      peVar5 = (esp_zb_uint48_t *)0x0;
    }
    else {
      peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x3c);
      if (peVar5 != (esp_zb_uint48_t *)0x0) {
        peVar3 = (esp_zb_uint48_t *)calloc(uVar6,6);
        if (peVar3 == (esp_zb_uint48_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(peVar3,(uint64_t *)peVar5,uVar6);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._2_1_ = (char)peVar3;
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._3_1_ =
             (char)((uint)peVar3 >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
             (char)((uint)peVar3 >> 0x10);
        app_message.snapshot_sub_payload.block_tier_delivered_no_billing.
        number_of_tiers_and_block_thresholds_in_use = (char)((uint)peVar3 >> 0x18);
        peVar5 = peVar3;
      }
    }
  }
  else {
    if (bVar1 != 5) goto _L0;
    array_copy_u64_to_u48
              ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
               (uint64_t *)((int)arg + 0x28),1);
    uVar6 = (uint)*(byte *)((int)arg + 0x30);
    app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
         *(byte *)((int)arg + 0x30);
    if (uVar6 == 0) {
      dst = (esp_zb_uint48_t *)0x0;
      peVar5 = (esp_zb_uint48_t *)0x0;
    }
    else {
      puVar4 = *(uint64_t **)((int)arg + 0x34);
      if (puVar4 == (uint64_t *)0x0) {
        dst = (esp_zb_uint48_t *)0x0;
        peVar5 = (esp_zb_uint48_t *)0x0;
      }
      else {
        dst = (esp_zb_uint48_t *)calloc(uVar6,6);
        if (dst == (esp_zb_uint48_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(dst,puVar4,uVar6);
        peVar5 = (esp_zb_uint48_t *)0x0;
        app_message.snapshot_sub_payload._3_4_ = dst;
      }
    }
  }
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_METERING_PUBLISH_SNAPSHOT_CB_ID,&uStack_58);
    eVar2 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x50) = eVar2;
  }
  if (dst != (esp_zb_uint48_t *)0x0) {
    free(dst);
  }
  if (peVar5 != (esp_zb_uint48_t *)0x0) {
    free(peVar5);
  }
  return;
}

