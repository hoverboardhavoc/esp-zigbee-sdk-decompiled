/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_publish_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_metering_publish_snapshot_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_zb_uint48_t *dst;
  esp_err_t err;
  uint uVar2;
  size_t __nmemb;
  undefined4 uVar3;
  uint64_t *puVar4;
  esp_zb_uint48_t *peVar5;
  esp_zb_uint48_t *peVar6;
  undefined2 uStack_58;
  undefined2 uStack_56;
  esp_zb_zcl_metering_publish_snapshot_message_t app_message;
  
  memset((void *)((int)&app_message.snapshot_time + 3),0,0x29);
  uStack_56 = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  uStack_58 = *arg;
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0x10);
  app_message.snapshot_time._2_1_ = *(undefined1 *)((int)arg + 0x1a);
  app_message.snapshot_id = *(uint32_t *)((int)arg + 0x14);
  app_message.snapshot_cause._0_1_ = *(byte *)((int)arg + 0x20);
  app_message._12_4_ = *(undefined4 *)((int)arg + 0x1c);
  app_message.snapshot_time._0_2_ = *(undefined2 *)((int)arg + 0x18);
  if ((byte)app_message.snapshot_cause == 4) {
_L0:
    array_copy_u64_to_u48
              ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
               (uint64_t *)((int)arg + 0x28),1);
    app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
         *(byte *)((int)arg + 0x30);
    uVar2 = (uint)(byte)app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.
                        low._2_1_;
    if ((uVar2 == 0) || (puVar4 = *(uint64_t **)((int)arg + 0x34), puVar4 == (uint64_t *)0x0)) {
_L0:
      if (cb == (esp_zb_core_action_callback_t)0x0) {
        return;
      }
      peVar5 = (esp_zb_uint48_t *)0x0;
      dst = (esp_zb_uint48_t *)0x0;
_L0:
      err = (*cb)(ESP_ZB_CORE_METERING_PUBLISH_SNAPSHOT_CB_ID,&uStack_58);
      eVar1 = esp_err_to_zcl_status(err);
      *(ezb_zcl_status_t *)((int)arg + 0x50) = eVar1;
      goto _L0;
    }
    dst = (esp_zb_uint48_t *)calloc(uVar2,6);
    if (dst == (esp_zb_uint48_t *)0x0) goto _L0;
    array_copy_u64_to_u48(dst,puVar4,uVar2);
    app_message.snapshot_sub_payload._3_4_ = dst;
_L0:
    peVar5 = (esp_zb_uint48_t *)0x0;
    if (cb != (esp_zb_core_action_callback_t)0x0) goto _L0;
  }
  else {
    if ((byte)app_message.snapshot_cause < 5) {
      if (((byte)app_message.snapshot_cause != 2) && ((byte)app_message.snapshot_cause != 3)) {
        array_copy_u64_to_u48
                  ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                   (uint64_t *)((int)arg + 0x28),1);
        app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
             (undefined1)*(undefined4 *)((int)arg + 0x30);
        app_message.snapshot_sub_payload._3_3_ =
             (undefined3)((uint)*(undefined4 *)((int)arg + 0x30) >> 8);
        uVar3 = *(undefined4 *)((int)arg + 0x34);
        app_message.snapshot_sub_payload.tou_delivered_no_billing.number_of_tiers_in_use =
             (char)uVar3;
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_1_ =
             (undefined1)((uint)uVar3 >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._2_1_ =
             (undefined1)((uint)uVar3 >> 0x10);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._3_1_ =
             (undefined1)((uint)uVar3 >> 0x18);
        uVar3 = *(undefined4 *)((int)arg + 0x38);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
             (undefined1)uVar3;
        app_message.snapshot_sub_payload.block_tier_delivered_no_billing.
        number_of_tiers_and_block_thresholds_in_use = (uint8_t)((uint)uVar3 >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._2_1_ =
             (undefined1)((uint)uVar3 >> 0x10);
        app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._3_1_ =
             (undefined1)((uint)uVar3 >> 0x18);
        uVar3 = *(undefined4 *)((int)arg + 0x3c);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._0_1_ =
             (undefined1)uVar3;
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._1_1_ =
             (undefined1)((uint)uVar3 >> 8);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._2_1_ =
             (undefined1)((uint)uVar3 >> 0x10);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._3_1_ =
             (undefined1)((uint)uVar3 >> 0x18);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._0_1_ =
             *(undefined1 *)((int)arg + 0x40);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._1_1_ =
             *(byte *)((int)arg + 0x41);
        uVar2 = (uint)(byte)app_message.snapshot_sub_payload.tou_delivered.
                            projected_bill_time_stamp_delivered._1_1_;
        if ((uVar2 == 0) || (puVar4 = *(uint64_t **)((int)arg + 0x44), puVar4 == (uint64_t *)0x0))
        goto _L0;
        dst = (esp_zb_uint48_t *)calloc(uVar2,6);
        if (dst == (esp_zb_uint48_t *)0x0) goto _L0;
        array_copy_u64_to_u48(dst,puVar4,uVar2);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._3_1_ =
             (undefined1)((uint)dst >> 8);
        app_message.snapshot_sub_payload.tou_delivered.bill_delivered_trailing_digit =
             (uint8_t)((uint)dst >> 0x10);
        app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._2_1_ =
             SUB41(dst,0);
        app_message.snapshot_sub_payload.tou_delivered.number_of_tiers_in_use =
             (uint8_t)((uint)dst >> 0x18);
        goto _L0;
      }
      array_copy_u64_to_u48
                ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                 (uint64_t *)((int)arg + 0x28),1);
      app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
           (undefined1)*(undefined4 *)((int)arg + 0x30);
      app_message.snapshot_sub_payload._3_3_ =
           (undefined3)((uint)*(undefined4 *)((int)arg + 0x30) >> 8);
      uVar3 = *(undefined4 *)((int)arg + 0x34);
      app_message.snapshot_sub_payload.tou_delivered_no_billing.number_of_tiers_in_use = (char)uVar3
      ;
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_1_ =
           (undefined1)((uint)uVar3 >> 8);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._2_1_ =
           (undefined1)((uint)uVar3 >> 0x10);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._3_1_ =
           (undefined1)((uint)uVar3 >> 0x18);
      uVar3 = *(undefined4 *)((int)arg + 0x38);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
           (undefined1)uVar3;
      app_message.snapshot_sub_payload.block_tier_delivered_no_billing.
      number_of_tiers_and_block_thresholds_in_use = (uint8_t)((uint)uVar3 >> 8);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._2_1_ =
           (undefined1)((uint)uVar3 >> 0x10);
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._3_1_ =
           (undefined1)((uint)uVar3 >> 0x18);
      uVar3 = *(undefined4 *)((int)arg + 0x3c);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._0_1_ =
           (undefined1)uVar3;
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._1_1_ =
           (undefined1)((uint)uVar3 >> 8);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._2_1_ =
           (undefined1)((uint)uVar3 >> 0x10);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_delivered._3_1_ =
           (undefined1)((uint)uVar3 >> 0x18);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._0_1_ =
           *(undefined1 *)((int)arg + 0x40);
      app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._1_1_ =
           *(byte *)((int)arg + 0x41);
      uVar2 = (uint)(byte)app_message.snapshot_sub_payload.tou_delivered.
                          projected_bill_time_stamp_delivered._1_1_;
      if (uVar2 == 0) {
        dst = (esp_zb_uint48_t *)0x0;
      }
      else {
        peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x44);
        dst = peVar5;
        if (peVar5 != (esp_zb_uint48_t *)0x0) {
          dst = (esp_zb_uint48_t *)calloc(uVar2,6);
          if (dst == (esp_zb_uint48_t *)0x0) goto _L0;
          array_copy_u64_to_u48(dst,(uint64_t *)peVar5,uVar2);
          app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._3_1_ =
               (undefined1)((uint)dst >> 8);
          app_message.snapshot_sub_payload.tou_delivered.bill_delivered_trailing_digit =
               (uint8_t)((uint)dst >> 0x10);
          app_message.snapshot_sub_payload.tou_delivered.projected_bill_time_stamp_delivered._2_1_ =
               SUB41(dst,0);
          app_message.snapshot_sub_payload.tou_delivered.number_of_tiers_in_use =
               (uint8_t)((uint)dst >> 0x18);
        }
      }
      app_message.snapshot_sub_payload._24_1_ = *(byte *)((int)arg + 0x48);
      uVar2 = (uint)(byte)app_message.snapshot_sub_payload._24_1_;
      if (uVar2 == 0) goto _L0;
      peVar6 = *(esp_zb_uint48_t **)((int)arg + 0x4c);
      peVar5 = peVar6;
      if (peVar6 != (esp_zb_uint48_t *)0x0) {
        peVar5 = (esp_zb_uint48_t *)calloc(uVar2,6);
        if (peVar5 == (esp_zb_uint48_t *)0x0) goto _L0;
        array_copy_u64_to_u48(peVar5,(uint64_t *)peVar6,uVar2);
        app_message.snapshot_sub_payload._25_2_ = SUB42(peVar5,0);
        app_message.snapshot_sub_payload._27_2_ = (undefined2)((uint)peVar5 >> 0x10);
      }
    }
    else {
      if ((byte)app_message.snapshot_cause == 6) {
        array_copy_u64_to_u48
                  ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                   (uint64_t *)((int)arg + 0x28),1);
        app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
             *(byte *)((int)arg + 0x30);
        __nmemb = (size_t)(byte)app_message.snapshot_sub_payload.tou_delivered.
                                current_summation_delivered.low._2_1_;
        if (__nmemb != 0) {
          peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x34);
          goto joined_r0x00013332;
        }
_L0:
        dst = (esp_zb_uint48_t *)0x0;
      }
      else {
        if ((byte)app_message.snapshot_cause != 7) {
          if ((byte)app_message.snapshot_cause != 5) {
            *(undefined1 *)((int)arg + 0x50) = 0x87;
            return;
          }
          goto _L0;
        }
        array_copy_u64_to_u48
                  ((esp_zb_uint48_t *)((int)&app_message.snapshot_cause + 1),
                   (uint64_t *)((int)arg + 0x28),1);
        app_message.snapshot_sub_payload.tou_delivered.current_summation_delivered.low._2_1_ =
             *(byte *)((int)arg + 0x30);
        __nmemb = (size_t)(byte)app_message.snapshot_sub_payload.tou_delivered.
                                current_summation_delivered.low._2_1_;
        if (__nmemb == 0) goto _L0;
        peVar5 = *(esp_zb_uint48_t **)((int)arg + 0x34);
joined_r0x00013332:
        dst = peVar5;
        if (peVar5 != (esp_zb_uint48_t *)0x0) {
          dst = (esp_zb_uint48_t *)calloc(__nmemb,6);
          if (dst == (esp_zb_uint48_t *)0x0) goto _L0;
          array_copy_u64_to_u48(dst,(uint64_t *)peVar5,__nmemb);
          app_message.snapshot_sub_payload._3_4_ = dst;
        }
      }
      app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._1_1_ =
           *(byte *)((int)arg + 0x38);
      uVar2 = (uint)(byte)app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered.
                          _1_1_;
      if (uVar2 == 0) {
_L0:
        peVar5 = (esp_zb_uint48_t *)0x0;
      }
      else {
        peVar6 = *(esp_zb_uint48_t **)((int)arg + 0x3c);
        peVar5 = peVar6;
        if (peVar6 != (esp_zb_uint48_t *)0x0) {
          peVar5 = (esp_zb_uint48_t *)calloc(uVar2,6);
          if (peVar5 == (esp_zb_uint48_t *)0x0) {
_L0:
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(peVar5,(uint64_t *)peVar6,uVar2);
          app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._3_1_ =
               (undefined1)((uint)peVar5 >> 8);
          app_message.snapshot_sub_payload.tou_delivered.bill_to_date_time_stamp_delivered._0_1_ =
               (undefined1)((uint)peVar5 >> 0x10);
          app_message.snapshot_sub_payload.tou_delivered.bill_to_date_delivered._2_1_ =
               SUB41(peVar5,0);
          app_message.snapshot_sub_payload.block_tier_delivered_no_billing.
          number_of_tiers_and_block_thresholds_in_use = (uint8_t)((uint)peVar5 >> 0x18);
        }
      }
    }
    if (cb != (esp_zb_core_action_callback_t)0x0) goto _L0;
_L0:
    if (dst == (esp_zb_uint48_t *)0x0) goto _L0;
  }
  free(dst);
_L0:
  if (peVar5 == (esp_zb_uint48_t *)0x0) {
    return;
  }
  free(peVar5);
  return;
}

