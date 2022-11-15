/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> cmd_zb_read_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_read_attr(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  uVar3 = get_free_row_attr_table();
  if (param_1 - 5U < 2) {
    if (param_1 == 6) {
      iVar4 = strcmp((char *)param_2[5],"switch");
      if (iVar4 == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if ((param_1 == 5) || (bVar1)) {
      if (uVar3 == 0xffffffff) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC12,uVar6,&_L0);
      }
      else {
        cVar2 = parse_address(*param_2,uVar3 * 0x3c + 0x11454,1);
        (&DAT_0001145c)[uVar3 * 0x3c] = cVar2;
        if (cVar2 == '\0') {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC13,uVar6,&_L0);
        }
        else {
          iVar4 = sscan_uint8(param_2[1],&DAT_0001145d + uVar3 * 0x3c);
          if (iVar4 == 0) {
            uVar6 = esp_log_timestamp();
            esp_log_write(1,&_L0,&_LC14,uVar6,&_L0);
          }
          else {
            pcVar7 = (char *)param_2[2];
            sVar5 = strlen(pcVar7);
            iVar4 = parse_hex_str(pcVar7,sVar5 & 0xff,&DAT_00011460 + uVar3 * 0x3c,2,1);
            if (iVar4 == 0) {
              uVar6 = esp_log_timestamp();
              esp_log_write(1,&_L0,&_LC15,uVar6,&_L0);
            }
            else {
              pcVar7 = (char *)param_2[3];
              sVar5 = strlen(pcVar7);
              iVar4 = parse_hex_str(pcVar7,sVar5 & 0xff,&DAT_0001145e + uVar3 * 0x3c,2,1);
              if (iVar4 == 0) {
                uVar6 = esp_log_timestamp();
                esp_log_write(1,&_L0,&_LC16,uVar6,&_L0);
              }
              else {
                pcVar7 = (char *)param_2[4];
                sVar5 = strlen(pcVar7);
                iVar4 = parse_hex_str(pcVar7,sVar5 & 0xff,&DAT_00011462 + uVar3 * 0x3c,2,1);
                if (iVar4 == 0) {
                  uVar6 = esp_log_timestamp();
                  esp_log_write(1,&_L0,&_LC17,uVar6,&_L0);
                }
                else {
                  if (bVar1) {
                    (&DAT_00011485)[uVar3 * 0x3c] = 1;
                  }
                  else {
                    (&DAT_00011485)[uVar3 * 0x3c] = 0;
                  }
                  *(undefined4 *)(&DAT_00011450 + uVar3 * 0x3c) = 0;
                  (&m_attr_table)[uVar3 * 0x3c] = 1;
                  iVar4 = zb_buf_get_out_delayed_ext_func(read_attr_send,uVar3 & 0xffff,0);
                  if (iVar4 != 0) {
                    uVar6 = esp_log_timestamp();
                    esp_log_write(1,&_L0,&_L0,uVar6,&_L0);
                    invalidate_row(uVar3 & 0xff);
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_L0,uVar6,&_L0);
    }
  }
  else {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_L0,uVar6,&_L0);
  }
  return;
}

