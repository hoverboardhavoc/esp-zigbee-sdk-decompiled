/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_nwk_addr_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_addr_rsp(int param_1,uint param_2,char *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 unaff_s3;
  ushort auStack_22 [7];
  
  if ((param_1 != 0) && (param_3 != (char *)0x0)) {
    if (param_4 == 0) {
      auStack_22[0] = 0;
      uVar2 = zmsg_get_length();
      af_read_le8(param_1,auStack_22,param_3);
      af_read_bytes(param_1,auStack_22,8,param_3 + 1);
      af_read_le16(param_1,auStack_22,param_3 + 10);
      if ((*param_3 == '\0') && (auStack_22[0] < uVar2)) {
        af_read_le8(param_1,auStack_22,param_3 + 0xc);
        if ((byte)param_3[0xc] != 0) {
          pvVar3 = calloc((uint)(byte)param_3[0xc],2);
          *(void **)(param_3 + 0x10) = pvVar3;
          if (pvVar3 == (void *)0x0) {
            return 0x8a;
          }
          af_read_le8(param_1,auStack_22,param_3 + 0xd);
          for (uVar4 = 0; uVar4 < (byte)param_3[0xc]; uVar4 = uVar4 + 1 & 0xff) {
            af_read_le16(param_1,auStack_22,*(int *)(param_3 + 0x10) + uVar4 * 2);
          }
        }
      }
      else {
        param_3[0xc] = '\0';
        param_3[0xd] = '\0';
        param_3[0x10] = '\0';
        param_3[0x11] = '\0';
        param_3[0x12] = '\0';
        param_3[0x13] = '\0';
      }
      if (uVar2 < auStack_22[0]) {
        unaff_s3 = 0xfe;
      }
      else {
        unaff_s3 = 0;
      }
    }
    else {
      auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*param_3);
      iVar1 = zmsg_append_bytes(1,auStack_22);
      if (iVar1 == 0) {
        iVar1 = zmsg_append_bytes(param_1,8,param_3 + 1);
        if (iVar1 == 0) {
          auStack_22[0] = *(ushort *)(param_3 + 10);
          iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
          if (iVar1 == 0) {
            if (*param_3 == '\0') {
              unaff_s3 = 0;
              if (param_2 == 1) {
                auStack_22[0]._0_1_ = param_3[0xc];
                iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
                if (iVar1 == 0) {
                  if (param_3[0xc] == '\0') {
                    unaff_s3 = 0;
                  }
                  else if (*(int *)(param_3 + 0x10) != 0) {
                    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_3[0xd]);
                    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
                    if (iVar1 == 0) {
                      for (param_2 = 0; param_2 < (byte)param_3[0xc]; param_2 = param_2 + 1 & 0xff)
                      {
                        auStack_22[0] = *(ushort *)(*(int *)(param_3 + 0x10) + param_2 * 2);
                        iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
                        if (iVar1 != 0) {
                          return 0x8a;
                        }
_L0:
                      }
                    }
                    else {
                      unaff_s3 = 0x8a;
                    }
                  }
                }
                else {
                  unaff_s3 = 0x8a;
                }
              }
            }
            else {
              unaff_s3 = 0;
            }
          }
          else {
            unaff_s3 = 0x8a;
          }
        }
        else {
          unaff_s3 = 0x8a;
        }
      }
      else {
        unaff_s3 = 0x8a;
      }
    }
    return unaff_s3;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x61,
                "zdo_op_nwk_addr_rsp","payload && rsp");
  goto _L0;
}

